#pragma once
#include <ostream>
class MyString
{
	//friend 전역함수의 의미
	//friend는 객체지향에 위배되는 문법이라 사용하지 않는것을 원칙으로 함
	//그러나 클래스와 전역함수가 밀접한 관계를 가질경우
	//전역함수를 클래스의 멤버인것처럼 쓰기 위해 friend를 선언할수 있다.
	//외부에 정의되어있지만, 원래는 클래스의 멤버로 쓰기 위한 함수만 friend로 선언한다.
	//friend선언시, 전역함수는 클래스의 private 멤버까지 접근이 가능하다.


	friend std::ostream& operator<<(std::ostream& out, MyString& myStr);
	friend std::istream& operator>>(std::istream& in, MyString& myStr);
public:
	MyString(const char* pStr);
	MyString();
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	MyString& operator+(const MyString& other);
	~MyString();
private:
	char* str; //문자열의 주소를 저장하는 포인터
	int length; //문자열의 길이를 저장
};