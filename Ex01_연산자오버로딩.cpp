#include <iostream>
#include "Point.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using namespace myName;


int main()
{
	Point p1(2, 3), p2(12, 30);
	Point p3 = p1;
	Point p4;
	Point p5;
	Point p6;

	//p4 = p1; //p4.operator
	//p5 = p4 = p1;

	//p6 = p4 + p2;

	++(++p1);

	p5 = p1 + 10;
	p6 = 10 + p1;

	cout << "p1" << p1.getPoint() << endl;
	cout << "p2" << p2.getPoint() << endl;
	cout << "p3" << p3.getPoint() << endl;
	cout << "p4" << p4.getPoint() << endl;
	cout << "p5" << p5.getPoint() << endl;
	cout << p1 - p2 << endl;


	//기존에 있는 연산자에 기능을 추가
	//좌측 피연산자가 호출, 우측이 인수가 됨. 메서드명:operator
	if (p1 == p2) //p1.operator==(p2)
		cout << "두 좌표는 같습니다.\n";
	else
		cout << "두 좌표는 다릅니다.\n";

	p1 += p2;
	return 0;
}
