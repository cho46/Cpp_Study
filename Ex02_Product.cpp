#include <iostream>
#include <string>
#include <cmath>
#pragma warning (disable:4996)
using std::cout;
using std::cin;
using std::endl;
using std::string;


class Product
{
public:
	Product(const string &name,const string &maker,const int &price)
	{

		this->name = name;
		this->maker = maker;
		this->price = price;
		num = num + count++;
	}
	~Product(){count--;}
	void displayProduct() const
	{
		cout << this->num << "\t" << this->name << "\t" << this->maker << "\t" << this->price << "원\n";
	}
	inline int getSerialNum() const { return this->num; }
	inline string getProductName()const{return this->name;}
	inline string getProductMaker()const {return this->maker;}
	inline int getProductPrice() { return this->price; }
	inline void setProductName(const string &name){this->name = name;}
	inline void setProductMaker(const string &maker) { this->maker = maker; }
	inline void setProductPrice(const int &price) { this->price = price; }
	inline static int getCount() { return count; }

	string getProductInfo() const
	{
		//to_string: string타입으로 변환, 문자열로 만들어서 출력
		return std::to_string(this->num) +" " + this->name + " " + this->maker + " " + std::to_string(this->price) + " 원";
	}

private:
	static int count;
private:
	int num = 1200;
	string name;
	string maker;
	int price;
};

int Product::count = 0;
int Product::getCount()
{
	return count;
}

int main()
{
	Product* p1 = new Product("새우깡", "농심(주)", 1900);
	Product* p2 = new Product("빼빼로", "롯데제과", 2200);
	Product* p3 = new Product("먹태깡", "농심(주)", 2500);

	cout << "[상품 리스트]\n";
	p1->displayProduct();
	p2->displayProduct();
	p3->displayProduct();
	cout << "-----------------------------------\n";
	cout << "p1 = " << p1->getProductInfo();
	cout << "총 상품 개수: " << Product::getCount() << "개";



	return 0;
}