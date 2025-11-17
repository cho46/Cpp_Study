#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <algorithm> //sort

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

//---------------------------------------------------------------------------Order클래스(카페 클래스)-------------------------------------------------------------------------
class Order
{
public:
	Order(string name, int quan, int price) : drinkName(name),quantity(quan),price(price){}

	string getDrinkName() const { return drinkName; }
	int getQuantity() const { return quantity; }
	int getPrice() const { return price; }
	int getTotal() const { return quantity* price; }

	void print() const
	{
		cout << "음료 : " << drinkName << " | 수량 : " << quantity << " | 가격 : " << price << " | 주문금액 : " << getTotal() << endl;
	}
protected:
private:
	string drinkName;
	int quantity;
	int price;
};
//---------------------------------------------------------------------------Cafe 클래스(컨트롤 클래스)-------------------------------------------------------------------------
class Cafe
{
public:
	//주문 추가하기
	void addOrder()
	{
		cout << "음료 이름 : ";
		string name;
		cin >> name;

		cout << "수량 : ";
		int count;
		cin >> count;

		cout << "가격(1잔기준) : ";
		int price;
		cin >> price;

		//emplace_back함수는 push_back함수와 비슷하지만, 백터 내부에서 바로 객체를 생성함
		//따라서, 이미 만들어진 객체를 복사하는 push_back()보다 성능상의 이점이 있다.
		orders.emplace_back(name,count,price); //백터에 주문추가
		cout << "\n\n\t\t[" << name << "]주문이 추가되었습니다.";
	}

	//주문 목록을 출력
	void showOrderList() const
	{
		cout << "\n\n\t * 주문 목록 출력 * \n";
		if (orders.empty())
		{
			cout << "\n\n\t\t 주문내역은 존재하지 않습니다.\n";
			return;
		}

		for (const auto& at : orders)
			at.print();

	}
	//총 매출액 출력
	void showTotalSale() const
	{
		int totalSale = 0;

		for (const auto& at : orders)
			totalSale += at.getTotal();

		cout << "매출 총액은 " << totalSale << "원 입니다.\n";
	}
	//주문삭제
	void removeOrder()
	{
		string delName;
		cout << "삭제할 음료 이름은 무엇인가요?";
		cin >> delName;
		bool isFound = false;
		for (auto it = orders.begin(); it != orders.end(); )
		{
			if (delName == it->getDrinkName())
			{
				//erase()함수의 반환값은 삭제된 원소 바로 다음 원소를 가리키는 iterator
				it = orders.erase(it);//벡터에서 제거
				isFound = true;
			}
			else
			{
				it++;
			}
		}
		if (isFound)
			cout << "\n\n\t\t요청하신 주문이 취소되었습니다.\n";
		else
			cout << "\n\n\t\t주문 내역이 존재하지 않습니다.\n";
	}

	//매출액 기준으로 정렬
	void sortSales()
	{
		std::sort(orders.begin(), orders.end(), compareSales);
	}

protected:
private:
	static bool compareSales(const Order& a, const Order& b)
	{
		//내림차순 정렬
		if (a.getTotal() > b.getTotal())
			return true;
		else
			return false;
	}
private:
	vector<Order> orders;
};

int main()
{
	Cafe myCafe; //인스턴스 생성
	int choice;
	while (true)
	{
		cout << "\n\n\t === 카페 주문 관리 ===\n\n";
		cout << "1. 주문 추가\n";
		cout << "2. 주문 목록 보기\n";
		cout << "3. 총 매출액 보기\n";
		cout << "4. 매출순으로 정렬\n";
		cout << "5. 주문 삭제\n";
		cout << "0. 프로그램 종료\n";

		cout << "\n메뉴 선택 : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			myCafe.addOrder();
			break;
		case 2:
			myCafe.showOrderList();
			break;
		case 3:
			myCafe.showTotalSale();
			break;
		case 4:
			myCafe.sortSales();
			break;
		case 5:
			myCafe.removeOrder();
			break;
		case 0:
			return 0;
		}
		cout << "\n\n\t\t";
		system("pause");
		system("cls");
	}
	return 0;
}