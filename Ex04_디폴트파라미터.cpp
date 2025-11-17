#include <iostream>
using namespace std;




int printChar(char ch = '*', int n = 10);

int main()
{
	printChar();

	char ch;
	int n;
	cout << "출력문자 / 개수 입력 : ";
	cin >> ch >> n;

	printChar(ch, n);



	return 0;
}

int printChar(char ch, int n)
{
	for (int i = 0; i <= n; i++)
		cout << ch;
	cout << endl;
	return 0;
}
