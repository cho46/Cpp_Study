#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using std::cin;
using std::cout;
using std::endl;

//클래스를 템플릿 => 클래스 X => 클래스를 만드는 틀
template <typename Type, int count>
class Stack
{
public:
	Stack();
	~Stack();
	Stack(const Stack& other)
	{
		this->capacity = other.capacity;
		this->arr = new Type[this->capacity];
		this->top = other.top;

		//스택의 내용을 복사 1. 반복문
		//for (int i = 0; i < this->capacity; i++)
			//this->arr[i] = other.arr[i];

		//메모리 카피 
		std::memcpy(this->arr, other.arr, this->capacity * sizeof(Type));
	}
	Stack& operator=(const Stack& other)
	{
		//기존 메모리를 제거
		if (this->arr) //this->arr !=nullptr
			delete[] this->arr;

		//새 객체 대입
		this->capacity = other.capacity;
		this->arr = new Type[this->capacity];
		this->top = other.top;

		std::memset(arr, 0, capacity * sizeof(Type)); //특정값으로 채우기

		//메모리 카피 
		std::memcpy(this->arr, other.arr, (this->top + 1) * sizeof(Type));

		return *this; //호출객체 리턴 => 연속적인 연산 수행
	}
	void push(Type value)
	{
		if (top == capacity - 1)
		{
			throw "Stack Overflow\n";
		}
		top++;
		arr[top] = value;
	}
	Type pop()
	{
		if (top == -1)
		{
			cout << "Stack Underflow\n";
			return -1;
		}
		//배열은 삭제 불가능 -> 코드를 삭제된것처럼 구현(논리적인 삭제)
		Type delvalue = arr[top];
		top--;
		return delvalue; //삭제된 값 리턴
	}
	Type peek()
	{
		if (top == -1)
		{
			return -1;
		}
		return arr[top];
	}
	bool isEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}
	void clear()
	{
		//논리적인 삭제
		top = -1;
	}
protected:
private:
	Type* arr = nullptr; //스택 메모리의 주소를 저장
	int capacity = 0; //스택의 최대 용량
	int top = -1; //꼭대기
};
template <typename Type, int count>
Stack<Type,count>::Stack()
{
	capacity = count; //스택의 사이즈 지정
	arr = new Type[capacity]; //스택 공간 생성
	std::memset(arr, 0, capacity * sizeof(Type)); //특정값으로 채우기
	top = -1;
}
template <typename Type, int count>
Stack<Type,count>::~Stack()
{
	delete[] arr; //동적 메모리 해제
}
int main()
{
	Stack<char,5> stk; //스택 인스턴스 생성 // char형 스택을 5개 생성
	//Stack stk2 = stk; //복사 생성자 생성
	//Stack stk3;
	//stk3 = stk; //stk3.operator=(stk)
	try
	{
		stk.push('a');
		stk.push('b');
		stk.push('c');
		stk.push('d');
		stk.push('e');
		stk.push('f');
	}
	catch (const char* exp)
	{
		cout << "아웃!";
	}
	cout <<"삭제된 값: " << stk.pop() << endl;
	cout << "삭제된 값: " << stk.pop() << endl;
	cout << "삭제된 값: " << stk.pop() << endl;
	
	cout << "꼭대기 값: " << stk.peek() << endl;

	cout << "스택이 비어 있나요? " << ((stk.isEmpty() == true) ? "예.":"아니요.") << endl;

	stk.clear();
	cout << "스택이 비어 있나요? " << ((stk.isEmpty() == true) ? "예." : "아니요.") << endl;

	return 0;
}