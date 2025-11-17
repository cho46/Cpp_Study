#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int** p = new int* [5];

	for (int i = 0; i < 5; i++)
		p[i] = new int [5];

	*(p[0] + 2) = 99;
	p[0][2] = 99;
	p[4][1] = -3;

	printf("%d", p[0][2]);



	for (int i = 0; i < 5; i++)
		delete[] p[i];

	delete[] p;

	return 0;
}