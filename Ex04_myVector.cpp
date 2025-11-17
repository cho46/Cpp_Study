#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::endl;
using std::cin;

//템플릿 클래스
template <typename Type>
class MyVector
{
public:
	class Iterator
	{
	public:
		Iterator(Type* p) : ptr(p) {}
		Type& operator* ()
		{
			return *ptr;
		}

		Iterator operator+(int increase)
		{
			return Iterator((ptr + increase));
		}

		Iterator operator-(int decrease)
		{
			return Iterator((ptr - decrease));
		}
		int operator-(Iterator it)
		{
			//포인터끼리 뺄셈을 수행하면 상대적인 거리(정수형)가 나옴
			int pos = (int)(this->ptr - it.ptr);
			return pos;
		}

		bool operator!=(const Iterator& it) const
		{
			//if (this->ptr != it.ptr)
			//	return true;
			//else
			//	return false;
			return (this->ptr != it.ptr);
		}

		Iterator operator++(int) //후치
		{
			Iterator temp = *this;
			++ptr;
			return temp;
		}
		Iterator& operator++() //전치
		{
			++ptr;
			return *this; //연속적인 연산을 수행하기 위해서
		}
		Iterator operator--(int) //후치
		{
			Iterator temp = *this;
			--ptr;
			return temp;
		}
		Iterator& operator--() //전치
		{
			--ptr;
			return *this; //연속적인 연산을 수행하기 위해서
		}


	private:
		Type* ptr; //현재 원소를 가키키는 포인터
	};
	Iterator begin()
	{
		return Iterator(arr); //첫 번째 원소의 주소로 인스턴스 생성
	}

	Iterator end()
	{
		return Iterator(arr + size); //마지막 원소의 다음 주소로 인스턴스 생성
	}
	MyVector() : arr(nullptr), size(0), capacity(0)
	{
	}

	template <typename... Types>
	MyVector(Type arg, Types... args)
	{
		//첫 번째 요소만 생성자에서 저장
		arr = new Type[1];
		*arr = arg;
		size = capacity = 1;

		//초기화 하는 함수를 호출해서 나머지 요소를 저장
		init(args...);
	}

	~MyVector()
	{
		delete[] arr;
	}

	template <typename... Types>
	void init(Type arg, Types... args)
	{
		if (capacity == size) //메모리가 꽉 찬 상태라면?
			memoryReallocCopy(); //메모리 재할당

		//값을 저장
		arr[size] = arg;
		//저장된 요소의 개수 증가
		++size;

		init(args...);
	}

	//마지막 요소를 저장하기 위한 함수
	void init(Type arg)
	{
		if (capacity == size)
			memoryReallocCopy();

		arr[size] = arg;
		size++;
	}

	inline Type& operator[](int index)
	{
		//인덱스로 값 저장 시 사용
		return arr[index];
	}

	inline const Type& operator[](int index) const
	{
		//값 리턴 시 사용
		return arr[index];
	}

	inline int getSize() const { return size; }

	void pushback(Type value)
	{
		if (size == capacity) //메모리 부족?
			memoryReallocCopy();

		arr[size] = value;
		size++;
	}
	inline void popback()
	{
		if (size == 0)
			throw std::underflow_error("MyVector::popback -> underflow");
		//논리적인 삭제
		--size;
	}
	Type front()
	{
		return arr[0];
	}
	Type back()
	{
		return arr[size-1];
	}
	Type at(int index)
	{
		if (index >= size)
			throw std::out_of_range("범위를 벗어났습니다.");
		else
			return arr[index];
	}
	void resize(int _size)
	{
		int temp = size;
		size = _size;
		if (size > capacity)
			capacity = size;
		memoryReallocCopy();
		for (int i = temp; i < size; i++)
			arr[i] = 0;
	}
	void reserve(int cSize)
	{
		capacity = cSize;
		Type* temp = new Type[capacity];
		for (int i = 0; i < size; i++)
			temp[i] = arr[i];
		delete[] arr;
		arr = temp;
	}

private:
	void memoryReallocCopy()
	{
		if (capacity == 0)
			capacity = 1;
		else if (capacity == 1)
			capacity = 2;
		else
			capacity = capacity + (capacity / 2); //0.5배 증가

		Type* temp = new Type[capacity];
		for (int i = 0; i < size; i++)
			temp[i] = arr[i]; //기존 데이터를 새 메모리에 복사

		delete[] arr;//기존 메모리 제거
		arr = temp; //새 주소로 변경
	}
private:
	Type* arr;		//벡터의 주소를 저장하는 포인터
	int size;		//저장된 개수
	int capacity;	//벡터의 최대 용량

public:
	
	//****************************
	// 내부 Iterator 클래스
	// 포인터와 비슷한 역할을 하는 클래스다.
	// 컨테이너의 원소를 가리키고, 그 원소를 읽거나 쓸 수 있게 한다.
	//****************************

	void insert(Iterator it, Type value)
	{
		//if (size == capacity)
		//	memoryReallocCopy();
		//Type temp;
		//for (auto ptr = it; ptr != end(); ptr++)
		//{
		//	temp = *ptr;
		//	*ptr = value;
		//	value = temp;
		//}
		//pushback(value);
		
		//뒤로 한칸씩 이동
		//삽입하려는 인덱스 구하기.
		int insertIdx = it - begin();

		if (size == capacity)
			memoryReallocCopy();
	
		//매모리 재할당시 it의 주소가 변경
		
		for (int i = size; i > insertIdx; i--)
			arr[i] = arr[i-1];

		arr[insertIdx] = value;
		++size;
		//*it = value;
	}
	void insert(Iterator it, int count, Type value)
	{
		int insertIdx = it - begin();
		if (size + count >= capacity)
		{
			reserve(size+count);
			//memoryReallocCopy();
		}
		
		for (int i = size-1; i >= insertIdx; i--)
			arr[i + count] = arr[i];

		for (int i = 0; i < count; i++)
		{
			arr[insertIdx + i] = value;
		}
		size += count;
	}
	void erase(Iterator st, Iterator ed)
	{
		int startIdx = st - begin();
		int endIdx = ed-begin();
		int count = endIdx - startIdx;
		for (int i = endIdx; i < size; i++)
			arr[i - count] = arr[i];
		size -= count;
	}

};

template <typename Type>
void display(MyVector<Type>& container)
{
	//for (int i = 0; i < container.getSize(); i++)
	//	cout << container[i] << " "; //container.operator[](i);
	//cout << endl;

	//for (auto it = container.begin(); it != container.end(); it++) //it.operator++()
	//	cout << *it << " ";
	//cout << endl;

	//C++11은 이터레이터를 직접 다루지 않고도 더 간단히 반복 가능
	//범위 for문은 내부적으로 begin()과 end()를 자동으로 사용한다.
	for (auto at : container)
		cout << at << " ";
	cout << endl;

}

int main()
{
	MyVector<int> v1{ 1, 2, 3, 4, 5 }; //인스턴스 생성 -> 생성자 호출
	display(v1);

	//MyVector<int>::Iterator it = v1.begin() + 2; //리턴객체.operator+(2);
	//cout << *it << endl; //it.operator*()
	//auto it2 = v1.end() - 3;
	//cout << *it2 << endl; //3

	//cout <<"front = " << v1.front() << endl;
	//cout << "back = " << v1.back() << endl;
	//cout << "at(2)= "<< v1.at(2) << endl;
	//v1.resize(10);
	//display(v1);
	//v1.reserve(12);
	//v1.insert(v1.begin() + 2, 99);
	//display(v1);
	//v1.insert(v1.begin()+2,5, 8);
	//display(v1);
	v1.erase(v1.begin()+1, v1.end()-1);
	display(v1);
	//MyVector<int> v2;
	//try
	//{
	//	v2.pushback(10); //맨 뒤에 요소 추가
	//	v2.pushback(20);
	//	v2.pushback(30);
	//	v2.popback(); //맨 뒤 요소 제거
	//	v2.popback(); //맨 뒤 요소 제거
	//	v2.popback(); //맨 뒤 요소 제거
	//	v2.popback(); //맨 뒤 요소 제거
	//}
	//catch (std::exception& exp)
	//{
	//	cout << exp.what() << endl;
	//}

	//display(v2);


	return 0;
}
//front, back, at, resize, reserve, erase, insert 구현하기.