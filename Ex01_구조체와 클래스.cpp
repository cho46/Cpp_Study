#include <iostream>
#include <cstring> //<string.h>
using std::cout;
using std::cin;
using std::endl;
#pragma warning (disable : 4996)


//계좌를 관리하는 구조체

class Account
{
public:
	//멤버 변수 =>attribute(속성)
	char addId[13]; //계좌번호 12자리
	char name[10]; //이름(한글명 4글자)
	char pw[5]; //비밀번호 4자리
	int balance; //잔액

	//멤버 함수 => method(메소드)
	void deposit(int increase);
	void withdraw(int decrease);
	void showBalance();
};
//멤버 함수 => method(메소드)
// 
// 메소드 외부정의할때
//클래스명::메소드명
void Account::deposit(int increase)
{
	balance += increase;
}

void Account::withdraw(int decrease)
{
	balance -= decrease;
}

void Account::showBalance()
{
	cout << name << " 고객님의 현재 잔액은" << balance << " 원 입니다." << endl;
}

//void deposit(Account& ref, int increase);
//void withdraw(Account& ref, int decrease);
//void showBalance(const Account& ref);
int main()
{
	Account acc = { "123-56789-12","천호영","1234",5000 };

	acc.deposit(8000);
	acc.withdraw(2000);

	acc.showBalance();

	return 0;
}


