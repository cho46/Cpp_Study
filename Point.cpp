#include "Point.h"
#include <math.h>
using namespace myName;

//전역함수 

Point myName::operator+(int num, const Point& other)
{
	return Point(other.x + num, other.y + num);
}
//


bool myName::Point::operator==(const Point& other)
{
	return (this->getX() == other.getX() && this->getY() == other.getY());
}

void myName::Point::operator+=(const Point& other)
{
	this->x += other.x;
	this->y += other.y;
	//cout << "p1+p2 =  (" << (this->getX() + other.getX()) << " , " << this->getY() + other.getY() <<")" << endl;
}

Point &Point::operator=(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "대입 연산자 호출(=)";
	return *this;
}

Point myName::Point::operator+(const Point& other) //지역변수는 래퍼런스로 리턴불가, 종료시 메모리상에서 삭제.
{
	//방법 1
	//Point temp;
	//temp.x += (this->x + other.x);
	//temp.y += (this->y + other.y);
	//return temp; 

	//방법2 
	/*Point temp(this->x + other.x, this->y + other.y);
	cout << "더하기(+) 연산자 호출";
	return temp;*/

	//방법 3. 임시 객체 생성
	return Point(this->x + other.x, this->y + other.y);
}

double myName::Point::operator-(const Point& other)
{
	double disx = std::pow(this->x - other.x, 2);
	double disy = std::pow(this->y - other.y, 2);
	return std::sqrt(disx + disy);
}

Point myName::Point::operator++()
{
	++(this->x);
	++(this->y);
	return *this; //연속적인 연산 수행
}

Point myName::Point::operator++(int)
{
	Point temp = *this;
	++(this->x);
	++(this->y);
	return temp;
}

Point myName::Point::operator+(int num)
{
	return Point(this->x += num, this->y += num);
}


