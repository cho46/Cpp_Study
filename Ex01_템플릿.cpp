#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using std::cin;
using std::cout;
using std::endl;

//함수 템플릿: 함수는 아님
template <typename T>
void swap(T& a, T& b);


template <typename T1, typename T2, typename T3>
void showData(T1 a, T2 b, T3 c);

template <typename Type>
int getSize(Type n);
//템플릿의 특수화, 똑같은 함수를 만듦
template<> int getSize(const char* n);


//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void swap(double& a, double& b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//}
//void swap(char& a, char& b)
//{
//	char temp = a;
//	a = b;
//	b = temp;
//}
int main()
{
	cout << "몇바이트?" << getSize(5) << endl;
	cout << "몇바이트?" << getSize(3.14) << endl;
	cout << "몇바이트?" << getSize('A') << endl;
	cout << "몇바이트?" << getSize("Hello World") << endl;



	showData<int, int, int>(1, 2, 3);
	showData<double, double, double>(3.5, 7.8, 9.2);
	showData<char,double,const char*>('A', 5.8, "Hello World");

	int a = 3, b = 5;
	swap<int>(a, b);
	cout << "교환된 값= " << a << " , " << b << endl;


	double d1 = 3.3, d2 = 5.2;
	swap<double>(d1, d2);
	cout << "교환된 값= " << d1 << " , " << d2 << endl;

	char c1 = 'A', c2 = 'B';
	swap<char>(c1, c2);
	cout << "교환된 값= " << c1 << " , " << c2 << endl;
	return 0;
}

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T1, typename T2, typename T3>
void showData(T1 a, T2 b, T3 c)
{
	cout << a << ", " << b << ", " << c << endl;
	cout << typeid(a).name() << ", " << typeid(b).name() << ", " << typeid(c).name() << endl;
}

template<typename Type>
int getSize(Type n)
{
	cout << "일반적인 타입은 여기에서 호출" << endl;
	return sizeof(n); //변수의 크기 리턴 = byte 리턴
}

template<>
int getSize(const char* n)
{
	cout << "특수화된 문자열 타입(const char*)만 여기서 호출" << endl;
	return std::strlen(n); //변수의 크기 리턴 = byte 리턴
}

