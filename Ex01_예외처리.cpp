#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using std::cin;
using std::cout;
using std::endl;


double divide(int a, int b);
int main()
{
	int a, b;
	cout << "정수 2개 입력: ";
	cin >> a >> b;

	try
	{
		if (b == 0)
			throw "0으로 나눌수 없습니다.";
		cout << divide(a,b) << endl;
	}
	catch (int exp)
	{
		cout << exp << "에러 슈웃!\n";
	}
	catch (const char* exp)
	{
		cout << exp << "\n";
	}
	
	return 0;
}

double divide(int a, int b)
{
	if (b == 0)
		throw "0으로 나눌 수 없습니다.";
	return a / b;
}