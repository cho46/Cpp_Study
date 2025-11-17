#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Dummy
{
	int aa = 0;
	double dd = 0;
	int* p = nullptr;
	double* p2 = nullptr;

public:
	Dummy()
	{
		cout << "1. 생성자\n";
	}
	Dummy(int a, double d)
	{
		aa = a;
		dd = d;
		p = new int;
		*p = a;
		p2 = new double;
		*p2 = d;
		cout << "2. 생성자\n";
	}
	~Dummy()
	{
		delete p;
		delete p2;
		cout << "~소멸자";
	}
	void show()
	{
		cout << aa << " , " << dd << " , " << *p << " , " << *p << endl;
	}
};

int main()
{
	Dummy* ptr; //주소를 저장하는 변수-> 포인터
	ptr = new Dummy(2, 3.5);
	ptr->show();
	delete ptr;

	return 0;
}