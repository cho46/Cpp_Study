#include <iostream>
using namespace std;

void input(int* n, double* d);
void input(int &n, double &d);
void swap(int *a, int * b);
void swap(int& a, int& b);

int main()
{
	//int n;
	//double d;

	//input(&n, &d); //call by address
	//input(n, d); // call by reference

	//cout << "입력결과는" << n << "," << d << "입니다.";
	
	int a = 3, b = 5;
	swap(&a, &b);


	cout << "address 교환결과는" << a << "," << b << "입니다."<<endl;

	swap(a, b);

	cout << "reference 교환결과는" << a << "," << b << "입니다."<<endl;

	return 0;
}

void input(int* n, double* d)
{
	cin >> *n;
	cin >> *d;
}

void input(int& n, double& d)
{
	cin >> n;
	cin >> d;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
