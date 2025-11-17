#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

#define OP_COUNT 8
enum eOper
{
	//열거형 : 앞에서부터 차례대로 0부터 1씩 증가하는 상수값을 취한다.
	//만약, 명시적으로 상수값을 설정 시 그 값부터 1씩 증가된다.
	SUM, SUB, MUL, DIV, POWER, POWER2, FACTORIAL,GCD
};

class Calculator
{
public:
	//instance method
	double sum(double d1, double d2);
	double sub(double d1, double d2);
	double mul(double d1, double d2);
	double div(double d1, double d2);
	double power(double x, double y);
	double powerOfTwo(int y);
	double factorial(int n); // 팩토리얼
	int gcd(int x, int y);

	//instance variable(iv)
	int count[OP_COUNT] = { 0 };

	void showOpCount();

};

double Calculator::sum(double d1, double d2)
{
	count[SUM]++;
	return d1 + d2;
}
double Calculator::sub(double d1, double d2)
{
	count[SUB]++;
	return d1 - d2;
}
double Calculator::mul(double d1, double d2)
{
	count[MUL]++;
	return d1 * d2;
}
double Calculator::div(double d1, double d2)
{
	count[DIV]++;
	return d1 / d2;
}
double Calculator::power(double x, double y)
{
	count[POWER]++;
	int result = 1;
	for (int i = 0; i < y; i++)
	{
		result *= x;
	}
	return result;
}
double Calculator::powerOfTwo(int y)
{
	count[POWER2]++;
	double result = 1;
	for (int i = 0; i < y; i++)
	{
		result *= 2;
	}
	return result;
}
double Calculator::factorial(int n) // 팩토리얼
{
	count[FACTORIAL]++;
	double result = 1;
	for (int i = n; i > 1; i++)
		result *= i;
	return result;
}
int Calculator::gcd(int x, int y)
{

	if (y == 0)
	{
		count[GCD]++;
		return  x; //최대 공약수
	}
	return gcd(y, x % y);
}

//instance variable(iv)
int count[OP_COUNT] = { 0 };
void Calculator::showOpCount()
{
	//고정소수점 형식			//정밀도(소수점 몇자리까지)
	cout << std::fixed << std::setprecision(6) << endl;
	cout << "\n 연산 횟수 출력\n";
	cout << "덧셈: " << count[SUM] << "회";
	cout << "뺄셈: " << count[SUB] << "회";
	cout << "곱셈: " << count[MUL] << "회";
	cout << "나눗셈: " << count[DIV] << "회";
	cout << "거듭제곱: " << count[POWER] << "회";
	cout << "2의 거듭제곱: " << count[POWER2] << "회";
	cout << "factorial: " << count[FACTORIAL] << "회";
	cout << "최대공약수(GCD): " << count[GCD] << "회";
}



int main()
{
	Calculator cal; //instance 생성
	cout << cal.sum(4,8.786) << endl;
	cout << cal.sum(36,89) << endl;
	cout << cal.sum(4.8789,61.75) << endl;
	cout << cal.gcd(72, 30) << endl;
	cout << cal.factorial(5) << endl;
	
	return 0;
}