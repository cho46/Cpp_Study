#include <iostream>
#include <cstring> //<string.h>
using std::cout;
using std::cin;
using std::endl;
#pragma warning (disable : 4996)

class UPPER
{
public:
	char ch;
	char final;
	void init();
	void upperChar();
};
void UPPER::init()
{
	cout << "변환할 영문자를 입력해 주세요: ";
	cin >> ch;
}
void UPPER::upperChar()
{
	if (ch >= 'A' && ch <= 'Z')
	{
		final = ch + 32;
		cout << "대문자" << ch << "를 소문자 " << final << "로 변환했습니다.";
	}
	else
	{
		final = ch - 32;
		cout << "소문자" << ch << "를 대문자 " << final << "로 변환했습니다.";
	}
}




int main()
{
	UPPER ch1;
	ch1.init();
	ch1.upperChar();
	


	return 0;
}