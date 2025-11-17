#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//int 형 메모리를 동적으로 할당하는 클래스
class DynamicIntArray
{

public:
	DynamicIntArray(int _size) 
	{
		if (_size > 0)
		{
			size = _size;
			arr = new int[size]; //동적할당
			std::memset(arr, 0,sizeof(int) * size);
			/*for (int i = 0; i < size; i++)
				arr[i] = 0;*/
			
		}
		cout << "Constructor : 동적 메모리 할당\n";
	}
	~DynamicIntArray()
	{
		if(size > 0)
			delete[] arr;
		cout << "Destructor : 동적 메모리 해제\n";
	}

public:
	void setAt(int index, int value)
	{
		if(index>0 && index<size) // 유효성 검사
			arr[index] = value;
	}
	int getAt(int index)
	{
		if (index > 0 && index < size)
			return arr[index];
		else
			return 0;
	}
	void resize(int resize)
	{
		int *arr2 = new int[resize];
		//for (int i = 0; i<size; i++)
		//{
		//	arr2[i] = arr[i];
		//}
		std::memset(arr, 0, sizeof(int) * resize);
		std::memcpy(arr2, arr, sizeof(int)*size);
		delete[] arr;
		arr = arr2;
		size = resize;
	}
	void setArray(int start, int step = 1)//특정값에서 1씩 증가되는 값을 저장
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = start + i*step;
		}
	}
	void displayArray()
	{
		cout << " [ ";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << " ] ";
	}
private:
	int* arr = nullptr; //동적 할당된 메모리의 주소를 저장하는 포인터 변수
	int size = 0; //동적 메모리의 크기
};

int main()
{
	DynamicIntArray d1(10); //인스턴스 생성
	d1.setAt(0, 55);
	d1.setAt(1, 66);

	cout << d1.getAt(0) << " , " << d1.getAt(1) << endl;

	d1.setArray(10000, 5);
	d1.displayArray();

	//for (int i = 0; i < 10; i++)
	//{
	//	d1.setAt(i, i + 1);
	//	cout << d1.getAt(i)<<"  ,  ";
	//}

	d1.resize(15);
	d1.setArray(5);

	d1.displayArray();
	return 0;
}