#include <iostream>
#include <string>
#include <functional>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::function;


int f_add(int a, int b)
{
	return a + b;
}
double f_square(int a)
{
	return a * a;
}

void f_hello()
{
	cout << "Hello World\n";
}

double f_getArea(double base, double height)
{
	return base * height / 2;
}

bool f_isEven(int num)
{
	return num % 2 == 0;
}

//만약 C++11을 사용한다면 템플릿을 권장
template <typename type>
auto calculatorTemp = [](type func, int a, int b) {
	return func(a, b);
	};

int main()
{
	//람다(lambda) 함수
	auto add = [](int a, int b) { return a + b; };
	auto square = [](int a) {return a * a; };
	auto hello = [](){cout << "Hello World\n";};
	auto getArea = [](double b, double h) {return b * h / 2; };
	auto isEven = [](int num) {return num % 2 == 0; };
	auto isOdd = [](int num) {return num % 2 != 0; };
	auto mul = [](int a, int b) {return a * b; };
	auto sub = [](int a, int b) {return a - b; };
	//C++14버전부터 가능함 가장 많이 사용되는 방식
	auto calculator = [](auto func, int a, int b) {
		return func(a, b);
		};

	//function 이용방법 -> 오버헤드가 커서 비용이 많이 든다. 추천X
	//function=> 함수를 담는 그릇
	//function<리턴타입(매개변수들...)>
	auto calculator11 = [](function<int(int,int)>func, int a, int b) {
		return func(a, b);
		};


	cout << "합 = " << f_add(3, 5) << endl;
	cout << "합 = " << add(3, 5) << endl;
	cout << "제곱 = " << f_square(3) << endl;
	f_hello();
	hello();
	isEven(2);

	cout << "calculator 호출 결과= " << calculator(mul, 3, 5) << endl;

	return 0;
}