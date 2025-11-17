#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;
using namespace std;

struct myTime
{
	int hour, minute, second;
};


void displayTime(const myTime time);
void addSecond(myTime time, int plus);
int main()
{
	myTime t1 = {8, 2, 3};
	myTime t2 = { 9, 5, 12 };
	myTime t3 = { 18, 16, 31 };

	addSecond(t1, 10000);
	addSecond(t2, 10000);
	addSecond(t3, 10000);
	cout << endl;

	displayTime(t1);
	displayTime(t2);
	displayTime(t3);

	return 0;
}

void displayTime(myTime time)
{
	cout <<std::setw(2)/*공백추가*/<<setfill('0')/*공백에 0 추가*/ << time.hour << "시 " << std::setw(2) << time.minute << "분 " << std::setw(2) << time.second << "초 " << endl;
}

void addSecond(myTime time, int plus)
{
	time.second += plus;
	int temp = time.second / 60;
	time.minute += temp;
	time.second -= temp * 60;

	if (time.minute > 59)
	{
		temp= time.minute / 60;
		time.hour += temp;
		time.minute -= temp * 60;
	}
	cout << "10000초후"<<endl;
	cout << std::setw(2)/*공백추가*/ << setfill('0')/*공백에 0 추가*/ << time.hour << "시 " << std::setw(2) << time.minute << "분 " << std::setw(2) << time.second << "초 " << endl;
}
