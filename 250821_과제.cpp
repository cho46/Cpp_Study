#include <iostream>
#include<iomanip>

using std::cout;
using std::endl;
using std::cin;

struct myDate
{
	int year, month, day;
};

bool leapYear(int year);
void addDays(myDate& ref, int increase);
void displayDate(const myDate& ref);

int main()
{
	myDate today{ 2025,8,21 };

	addDays(today, 1000);

	cout << "오늘 만난 사람과 1000일 뒤인 날짜는? ";
	displayDate(today);


	return 0;
}
bool leapYear(int year) // 윤년계산
{
	//4년마다 한번씩 돌아오는 해
	//100년마다 돌아오면 평년, 그러나 다시 400년마다 돌아오면 윤년이 됨.
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	else if (year % 400 == 0)
		return true;
	return false;
}


void addDays(myDate& ref, int increase)
{
		int days[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int total = 0;
		int k,j;

		for (int i = 0; i < ref.year; i++)
			leapYear(i) ? total += 366 : total += 365;
		for (int j = 1; j <= ref.month - 1; j++)
			total += days[j];
		total += ref.day + increase;

		for (k = 0; total>=(leapYear(k)?366:355); k++)
			leapYear(k) ? total -= 366 : total -= 365;
		ref.year = k;
		leapYear(ref.year) ? days[2] = 29 : days[2] = 28;
		for (j= 1; total > days[j]; j++)
			total -= days[j];
		ref.month = j;

		ref.day = total-1;
}

void displayDate(const myDate& ref)
{
	cout << ref.year << "년" << ref.month << "월" << ref.day << "일";
}
