#include <iostream>
#include <cstring> //<string.h>
using std::cout;
using std::cin;
using std::endl;
#pragma warning (disable : 4996)

class CALC
{
public:
	int stNum = 0,enNum = 0;

	void init();
	void printCalc();
};
void CALC::init()
{
	cout << "시작 단: ";
	cin >> stNum;
	cout << "끝 단: ";
	cin >> enNum;
	cout << endl;
}
void CALC::printCalc()
{
	for (int i = stNum; i <= enNum; i++)
	{
		cout << "===============" << i << "단" << "===============" << endl;
		for (int j = 0; j <= 9; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << endl;
	}
}


int main()
{
	CALC c1;
	c1.init();
	c1.printCalc();



	return 0;
}