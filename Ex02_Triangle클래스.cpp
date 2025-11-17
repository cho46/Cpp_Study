#include <iostream>
#include <cstring> //<string.h>
using std::cout;
using std::cin;
using std::endl;
#pragma warning (disable : 4996)

//클래스는 삼각형이 아닌 삼각형을 만드는 틀임.
class Triangle
{
public:
	//*instance variable(iv)*=> attribute
	double base = 0, height = 0;

	void init(double b, double h);

	double getArea();

};
//*instance method(im)*
void Triangle::init(double b, double h)
{
	base = b;
	height = h;
}

double Triangle::getArea()
{
	return base * height / 2;
}

int main()
{
	Triangle t1, t2; //삼각형 => 객체(object) => *인스턴스(instance)*
	
	t1.init(8, 9);
	t2.init(100, 200);

	cout << "t1의 넓이는" << t1.getArea() << "입니다";
	cout << "t2의 넓이는" << t2.getArea() << "입니다";
	return 0;
}