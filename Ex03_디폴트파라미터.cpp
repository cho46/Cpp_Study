#include <iostream>
using namespace std;

//int getTotal();
//int getTotal(int x);
int getTotal(int x = 1, int y = 100); //default parameter 선언부에만 명시, 정의부는 디폴트값을 쓰지 않는다.

int main()
{

	cout << "1~100의 합 = " << getTotal() << endl;
	cout << "50~100의 합 = " << getTotal(50) << endl;
	cout << "70~90의 합 = " << getTotal(70, 90) << endl;



	return 0;
}

//int getTotal()
//{
//	int total = 0;
//	for (int i = 1; i <= 100; i++)
//		total += i;
//
//	return total;
//}
//
//int getTotal(int x)
//{
//	int total = 0;
//	for (int i = x; i <= 100; i++)
//		total += i;
//	return total;
//}

int getTotal(int x, int y)
{
	int total = 0;
	for (int i = x; i <= y; i++)
		total += i;
	return total;
}
