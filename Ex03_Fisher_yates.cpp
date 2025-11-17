#include <iostream>
#include "ConsoleUtils.h"
#include <string>
#include <cstdlib>
#include	<ctime>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (const int& el : a)
	{
		cout << el << " ";
	}
	cout << endl;
	std::srand((unsigned int)std::time(NULL));
	//ÇÇ¼Å -¿¹ÀÌÃ÷ ¼ÅÇÃ
	for (int i = 9; i > 0; i--)
	{
		int index = rand() % (i + 1);
		std::swap(a[i], a[index]); //°ª ±³È¯
	}

	for (const int& el : a)
	{
		cout << el << " ";
	}
	return 0;
}