#include "Mystring.h"
#include <cstring>
#include <iostream>
#include "ostream"
#include "istream"
using namespace std;


#pragma warning (disable:4996)

// 전역함수----------------------------------------------------------------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out, MyString& myStr)
{
	out << myStr.str;
	return out; //연속적인연산(출력)을 할수있음.
}
std::istream& operator>>(std::istream& in, MyString& myStr)
{
	char buf[1024 * 254];
	in >> buf; //임시 변수에 입력을 받음
	myStr.length = std::strlen(buf);
	myStr.str = new char[myStr.length + 1];
	std::strcpy(myStr.str, buf);

	return in; //연속적인 입력을 위해 cin리턴
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
MyString::MyString() : str(nullptr), length(0)
{
	cout << "1. 기본값 생성자 호출\n";
}
MyString::MyString(const MyString& other)
{
	this->length = other.length;
	str = new char[this->length+1];
	strcpy(this->str, other.str);
	cout << "3. 복사생성자 호출\n";
}
MyString::MyString(const char* pStr)
{
	length = (int)std::strlen(pStr);
	str = new char[length + 1];
	strcpy(str, pStr);
	cout << "2. 생성자 호출\n";
}
MyString::~MyString()
{
	delete[] str;
	cout << "~소멸자 호출\n";
}
MyString& MyString::operator=(const MyString& other)
{
	this->length = other.length;
	str = new char[this->length + 1];
	strcpy(this->str, other.str);
	std::cout << "=연산자 호출\n";

	return *this;
	
}

MyString& MyString::operator+(const MyString& other)
{
	MyString temp;
	temp.length = this->length + other.length;
	temp.str = new char[temp.length+1];
	strcpy(temp.str, this->str);
	strcat(temp.str, other.str);

	return temp;
}
