#include <iostream>
using std::cin;
using std::cout;
using std::endl;
bool isBigger(int a,int b)
{
	if (a > b)
		return true;
	else
		return false;
}
bool isEqual(int a, int b)
{
	if (a == b)
		return true;
	else
		return false;
}

void showPairIf(int *a, int *b, int size, bool(*check)(int a, int b))
{
	for (int i = 0; i < size; i++)
	{
		if (check(a[i],b[i]))
			cout << "( " << a[i] <<", " << b[i] << ")" << endl;
	}
}
int main()
{
	int a[5] = { 3,7,2,9,5 };
	int b[5] = { 4,7,1,8,6 };
	printf("a°¡ bº¸´Ù Å« ½Ö: \n");
	showPairIf(a, b, 5, isBigger);

	printf("a°¡ b¿Í °°Àº ½Ö: \n");
	showPairIf(a, b, 5, isEqual);
	return 0;
}