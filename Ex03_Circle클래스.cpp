#include <iostream>
#include <cstring> //<string.h>
using std::cout;
using std::cin;
using std::endl;
#pragma warning (disable : 4996)

class Circle
{
public:
	//instance variable
	double radius = 0;
	const double PI = 3.141592;

	void init(double rad);
	double getArea();
	double getCircumference();
};
void Circle::init(double rad)
{
	radius = rad;
}
double Circle::getArea()
{
	return PI * radius * radius;
}
double Circle::getCircumference()
{
	return 2 * PI * radius;
}


int main()
{
	Circle c1;
	c1.init(6);

	cout << "원의 둘레= " << c1.getCircumference() << endl;

	return 0;
}