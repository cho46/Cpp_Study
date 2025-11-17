#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int max(int a, int b)
{
	if (a > b)
		return 0;
	else
		return b;
}
int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

void doNothing(double d, char c, int i)
{
	cout << "doNothing\n";
}

double doSomething(const char* str)
{
	cout <<str<< "\n";
	return 1.0;
}


int main()
{
	double (*dst)(const char*) = doSomething;
	dst("hi");


	void (*ddd)(double, char, int);
	ddd = doNothing;


	int(*ptr) (int, int);
	ptr = max;

	cout << "Å« ¼ö= " << max(3, 5) << endl;
	return 0;
}