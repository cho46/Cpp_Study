#include <iostream>
#include "Point.h"
using std::cout;
using std::cin;
using std::cout;
using std::endl;
using namespace myName;
#pragma warning (disable:4996)

int main()
{
	Point* ptr = nullptr;
	ptr = new Point[3]{ Point(1,10) };


	for (int i = 0; i < 3; i++)
	{
		cout << ptr[i].getX() <<"," << ptr[i].getY()<<endl;
	}

	cout << "Ã¹¹øÂ° ÁÂÇ¥" << ptr->getX() << "," << ptr->getY() << endl;

	delete[] ptr;
	return 0;
}