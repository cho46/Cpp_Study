#include <iostream>
#include <string>
#include <initializer_list>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//-------------------------------------------------------------------노드를 저장하는 구조체 템플릿
template <typename T>
struct Node
{
	T value;
	Node<T>* next;

	Node(const T& val) : value(val),next(nullptr) {}
};
//---------------------------------------------------단일 연결리스트 기반으로 동작하는 STL 구현
template <typename T>
class MyList
{
public:
	//이름변경 Node<T>를 Node이름으로 사용함.
	using Node = Node<T>;
	//using INTEGER = int;
public:
	//-----------------------------------------내부 클래스 Iterator-----------------------------------------//
	//---------------------------------------- 포인터로 동작------------------------------------------------//
	class Iterator
	{
	public:
		Iterator(Node* ptr) : current(ptr) {}
		T& operator*()
		{
			//현재 위치 역참조
			return current->value;
		}
		bool operator!=(const Iterator& other)
		{
			if (this->current != other.current)
				return true;
			else
				return false;
		}
		Iterator operator++() //전치
		{
			if(current!=nullptr)
				current = current->next;
			return *this; //자기자신을 리턴(연속적인 연산을 가능하게 하기 위해서
		}
		Iterator operator++(int) //후치
		{
			Iterator temp = *this;
			++(*this);
			return temp;
		}
		Node* getNodePointer()
		{
			return current;
		}
	private:
		Node* current;
	};
	Iterator begin()
	{
		//임시객체를 생성해서 리턴
		return Iterator(head); //첫 노드의 주소를 저장해서 리턴
	}
	Iterator end()
	{
		return Iterator(nullptr); //마지막 노드의 다음주소를 저장해서 리턴
	}
	//-----------------------------------------내부 클래스 Iterator-----------------------------------------//
public:
	MyList() : head(nullptr) {}
	MyList(std::initializer_list<T> init)
	{
		head = nullptr;
		Node* tail = nullptr;
		for (const auto& el : init)
		{
			//노드 생성
			Node* newNode = new Node(el);

			//노드를 연결하나 헤드가 null인경우
			if (head == nullptr)
			{
				head = newNode;
				tail = newNode;
			}
			else
			{
				tail->next = newNode;
				tail = newNode;
			}
		}
	}
	~MyList() {clear();} //메모리 누수 방지
	void pushFront(T value)
	{
		//노드 생성
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}
	void popFront()
	{
		if (!head)
			return;
		Node* delNode = head;
		head = head->next;
		delete delNode;
	}
	void clear()
	{
		//모든 노드 제거
		//첫 노드 제거 => 반복
		while (head!=nullptr)
		{
			Node* delNode = head;
			head = head->next;
			delete delNode;
		}
	}
	void insert_after(Iterator other,const T& value)
	{
		/*Node* newNode = new Node(value);
		newNode->next = other.current->next;
		other.current->next = newNode;*/

		//현재 위치의 주소를 리턴
		Node* curNode = other.getNodePointer();

		if (!curNode)
			return;
		//노드 생성
		Node* newNode = new Node(value);
		newNode->next = curNode->next;
		curNode->next = newNode;
	}
	void erase_after(Iterator other)
	{
		/*Node* temp = other.current;
		Node* delNode = other.current->next;
		temp->next = delNode->next;
		delete delNode;*/

		Node* curNode = other.getNodePointer();
		if (!curNode||!curNode->next)//노드가 없거나 1개인경우 삭제불가
			return;
		Node* delNode = curNode->next;
		curNode->next = delNode->next;
		delete delNode;

	}
private:
	Node* head;
};
int main()
{
	MyList<int> li;
	MyList<int> l2 = { 1,2,3,4,5,6,7 };

	l2.pushFront(99); //맨앞에 값 삽입

	//l2.popFront(); //맨 앞 삭제

	MyList<int>::Iterator it = l2.begin();
	cout << *it << endl; //it.operator*()

	for (auto p = l2.begin(); p!=l2.end(); ++p) //p.operator!=(Iterator)
	{
		cout << *p << " ";
	}
	cout<<"--------------------------------------\n";
	l2.insert_after(l2.begin(), -3); // 99 -3 1 2 3 4 5 6 7
	for (auto el : l2)
		cout << el << " ";
	cout << endl;
	l2.erase_after(l2.begin()); //99 1 2 3 4 5 6 7 
	for (auto el : l2)
		cout << el << " ";
	cout << endl;
	//Iterator 가 구현되면 범위기반 for문을 사용할 수 있음. =>내부적으로 범위기반 for문은 Iterator로 동작하기 때문이다.

	return 0;
}