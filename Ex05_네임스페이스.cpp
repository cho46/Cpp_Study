#include <iostream>

using namespace std;


namespace No1
{
	void fun()
	{
		cout << "1. fun\n";
	}
}
namespace No2
{
	void fun()
	{
		cout << "2. fun\n";
	}
}

namespace No3
{
	void fun()
	{
		cout << "3. fun\n";
	}
}

namespace No4
{
	void fun()
	{
		cout << "4. fun\n";
	}
}

//using namespace No3;
//using No3::fun;
int main()
{
	//:: 범위(영역) 지정 연산자
	No3::fun();


}