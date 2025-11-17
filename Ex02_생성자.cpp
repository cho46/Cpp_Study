#include <iostream>
using std::cout;
using std::cin;
using std::endl;


class Point
{
public:
	//Point()
	//{
	//	cout << "2. 생성자(Constructor): iv초기화 목적\n";
	//}
	Point(int _x = 0, int _y = 0);
public:
	int getx();
	int gety();
	void setx(int a);
	void sety(int a);

private:
	int x = 0, y = 0;
};
Point::Point(int _x = 0, int _y = 0)
{
	x = _x;
	y = _y;
	cout << "1. 생성자(Constructor): iv초기화 목적\n";
}

int Point::getx()
{
	return x;
}

int Point::gety()
{
	return y;
}

void Point::setx(int a)
{
	x = a;
}

void Point::sety(int a)
{
	y = a;
}

int main()
{
	Point p1(5,9),p2; //인스턴스 생성

	

	cout << "p1(" << p1.getx() << " , " << p1.gety() << ")" << ")\n";
	p2.setx(5);
	p2.sety(6);
	cout << "p2(" << p2.getx() << " , " << p2.gety() << ")" << ")\n";


	return 0;
}