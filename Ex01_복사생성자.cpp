#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::string;
#pragma warning (disable:4996)


//문자열을 길이에 상관없이 동적저장하는 클래스
class Mystring
{
public:
	Mystring(const char* const p)
	{
		length = std::strlen(p);

		str = new char[length + 1];
		std::strcpy(str,p);
		cout << "생성자: 문자열 저장\n";

	}
	Mystring(const Mystring& other)
	{
		//얕은 복사: 이방법으로는 동적메모리까지 복사못함
		//this->str = other.str;
		//this->length = other.length;

		//깊은 복사: 동적메모리까지 모두 복사
		this->length = other.length;
		new char[this->length+1];
		std::strcpy(this->str, other.str);
	}
	~Mystring()
	{
		delete[] str;
		cout << "소멸자: 동적으로 할당된 메모리 제거";
	}
	inline const char* const getString() const
	{
		return str;
	}
private:
	char* str = nullptr;
	int length = 0;

};

int main()
{
	Mystring s1 = "Hello World";
	Mystring s2 = "orange";
	Mystring s3 = s2;

	cout << "s1 = " << s1.getString() << endl;
	cout << "s2 = " << s2.getString() << endl;
	cout << "s3 = " << s3.getString() << endl;
	return 0;
}