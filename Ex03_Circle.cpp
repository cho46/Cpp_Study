#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
#define PI 3.14

#pragma warning(disable:4996)

class Circle
{
public:
	Circle(string s1, string s2, double _size)
	{
		kind = s1;
		flavor = s2;
		if(_size>0)
			size = _size;
	}
	double getArea()
	{
		double area = PI * size * size;
		return area;
	}
	void show()
	{
		cout << "Á¾·ù: " << kind << "  ¸À: " << flavor << "  Å©±â: " << getArea() << endl;
	}

public:
	string getKind()
	{
		return kind;
	}
	string getflavor()
	{
		return flavor;
	}
public:
	void setRadius(double _rad)
	{
		size = _rad;
		getArea();
	}
	void setKind(string _kind) 
	{ 
		kind = _kind;
	}
	void setKind(string _flavor)
	{
		flavor = _flavor;
	}

private:
	string kind, flavor;
	double size = 1;

};


int main()
{
	Circle doughnut("µµ³Ó", "½´Å©¸²", 5);
	Circle pizza("ÇÇÀÚ", "Ä¡Áî", 20);
	Circle waffle("¿ÍÇÃ", "»ýÅ©¸²", 10);

	doughnut.show();
	pizza.show();
	waffle.show();

	cout << "µµ³ÓÀº ¹«½¼¸ÀÀÎ°¡¿ä?" << doughnut.getflavor() << endl;

	doughnut.setRadius(5);


	return 0;
}