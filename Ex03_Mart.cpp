#include <iostream>
#include <string>
#include <cmath>
#pragma warning (disable:4996)
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

class Mart
{
public:
	Mart(string name,int price)
	{
		this->name = name;
		this->price = price;
	}
	string getName() { return this->name; }
	int getprice() { return this->price; }

	void sell(int cnt)
	{
		cout << this->name << cnt << "개를 팔았습니다.\n";
		sellcount += cnt;
		totalcnt += cnt;
	}
	void refund(int cnt)
	{
		cout << this->name << cnt << "개가 환불되었습니다.\n";
		sellcount -= cnt;
		totalcnt -= cnt;
	}
	void sellInfo()
	{
		cout << this->name + to_string(this->price) + to_string(this->sellcount);
	}
	static int getSoldCount() {return totalcnt;}
private:
	static int sellcount;
	string name;
	int price;
	static int totalcnt;
};
int Mart::totalcnt = 0;
int Mart::getSoldCount() { return totalcnt; }

int main()
{
	Mart* m1 = new Mart("노트북", 890000);
	Mart* m2 = new Mart("스마트폰", 1200000);
	
	m1->sell(3); // 노트북 3개 팔았습니다.
	m2->sell(2); // 스마트폰 2개 팔았습니다.
	m1->refund(1); //노트북 1개가 환불되었습니다.
	m1->sell(5); // 노트북 5개 팔았습니다.

	cout << " *상품 목록 당 판매현황 *\n";
	//[제품정보][가격][판매량:_개]
	cout << m1->sellInfo() << endl; //[노트북][890000][판매량:7개]
	cout << m2->sellInfo() << endl; //[스마트폰][1200000][판매량:2개]

	cout << "NH Mart 전체 판매량\n";
	cout << "전체 판매량은 " << Mart::getSoldCount() << endl;

	return 0;
}