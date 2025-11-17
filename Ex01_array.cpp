//STL: Standard Template Library

#include <iostream>
#include <cstdlib> //qsort
#include <cstring> //strcmp
#include <string> //string 문자열
#include <array> //array STL: 고정크기 배열

using std::cin;
using std::cout;
using std::endl;
using std::array;

struct citizen
{
	std::string name;
	int age;
};

std::ostream& operator<<(std::ostream& out, const citizen&city)
{
	out << "[" << city.name << " , " << city.age << "]";
	return out;
}

template <typename Type,int count>
void display(const array<Type,count>&other)
{
	for (const auto& at : other)
		cout << at << " "; //operator<<(cout,at);
	cout << endl;
}

int main()
{
	//int a[5] = { 1,2,3 };

	array<int, 5> a = { 1,2,3 };
	array<char, 5> b = { 1,2,3,4,5 };

	char ch[3] = { 'a','b','c' };
	array<char,3> ch = { 'a','b','c' };

	//citizen ci[3] = { {"나길동",55},{"고길동",34},{"차길동",27} };
	array<citizen,3> c1 = { "나길동",55, "고길동",34,"차길동",27};

	cout << a.size() << endl; //배열의 사이즈 보기

	//cout << a[0] << endl; == cout << a.at(0); == a.front() =>첫번째 값 보기
	//cout<< a[4] <<endl; == cout<<a.back()<<endl; => 마지막 값 보기
	a.fill(9);

	display(a);
	display(ch);
	display(c1);
	try
	{
		//cout << a[3] << endl; //빠른 성능을 위해 thorw를 던지지 않음
		cout << a.at(100) << endl; //매번 유효성 체크를 진행함(범위 체크) - 성능은 떨어지나, 안정성 향상
	}
	catch (std::exception& exp)
	{
		cout << exp.what() << endl;
	}
	return 0;
}