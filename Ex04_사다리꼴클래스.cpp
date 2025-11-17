#include <iostream>
#include <cstring> //<string.h>
using std::cout;
using std::cin;
using std::endl;
#pragma warning (disable : 4996)

class 사다리꼴
{
public:
	double up = 0, under = 0, height = 0;
	
	void init(double u, double un, double he)
	{
		up = u;
		under = un;
		height = he;
	}
	double getArea()
	{
		return ((up + under) * height) / 2;
	}

};


int main()
{
	사다리꼴 t1;
	t1.init(4, 5, 6);
	cout<<"사다리꼴의 넓이는" << t1.getArea()<<"입니다.";


	return 0;
}