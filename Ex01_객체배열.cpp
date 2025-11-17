#include <iostream>
#include "Point.h"

using namespace myName;
int main()
{
	//Point p1, p2, p3, p4, p5;
	Point p[5] = {Point(1,10),Point(2,20),Point(3,30),Point(4,40),Point(5,50)};

	for (int i = 0; i < 5; i++)
	{
		cout << p[i].getX() << p[i].getY() << endl;
	}

	/*cout << "p[0]" << p[0].getX() << "," << p[0].getY() << endl;
	cout << "p[1]" << p[1].getX() << "," << p[1].getY() << endl;
	cout << "p[2]" << p[2].getX() << "," << p[2].getY() << endl;
	cout << "p[3]" << p[3].getX() << "," << p[3].getY() << endl;
	cout << "p[4]" << p[4].getX() << "," << p[4].getY() << endl;*/

	return 0;
}