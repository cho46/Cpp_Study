#include <iostream>
#include<iomanip>

using std::cout;
using std::endl;
using std::cin;

bool isUpper(char ch);
bool leafYear(int year);
int main()
{
	int year;
	cout << "년도 입력: ";
	cin >> year;

	//leafYear: 윤년이면 True, 아닐경우 false 반환
	if (leafYear(year))
		cout << "윤년입니다.";
	else
		cout << "평년입니다.";

	char ch;
	cout << "문자입력: ";
	cin >> ch;

	if (isUpper(ch))
		cout << "대문자입니다.\n";
	else
		cout << "대문자가 아닙니다.\n";



	return 0;
}

bool isUpper(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return true;

	return false;
}

bool leafYear(int year) // 윤년계산
{
	//4년마다 한번씩 돌아오는 해
	//100년마다 돌아오면 평년, 그러나 다시 400년마다 돌아오면 윤년이 됨.
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	else if (year % 400 == 0)
		return true;
	return false;
}
