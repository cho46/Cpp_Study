#include "Mystring.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;
using std::cin;

std::istream& operator>>(std::istream& in, MyString& myStr)
{
	char buf[1024*254];
	in >> buf; //임시 변수에 입력을 받음
	myStr.length = std::strlen(buf);
	myStr.str = new char[myStr.length+1];
	std::strcpy(myStr.str, buf);

	return in; //연속적인 입력을 위해 cin리턴
}
int main()
{
	MyString s1 = "apple"; 
	MyString s2 = "strawberry";
	MyString s3; //기본생성자 호출
	s3 = s2; //s3.operator=(s2)
	MyString s4(s1); //MyString s4(s1) =>복사생성자 호출

	MyString s5 = s1 + s2;
	MyString s6;

	cout << "문자열 입력";
	cin >> s6;
	cout << "입력받은 문자열은 " << s6 << "입니다\n";

	cout << "s1 = " << s1 << endl; //cout.operator<<
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s5 = " << s5 << endl;
	return 0;
}