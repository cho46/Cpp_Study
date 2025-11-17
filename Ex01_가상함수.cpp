#include <iostream>
#include <cstdlib> //qsort
#include <cstring>
#include <string>
using std::cin;
using std::cout;
using std::endl;

//추상 클래스: 순수 가상함수를 한개 이상 포함한 클래스
//객체 생성이 불가능하다.
//Character ch;(X)
//객체 포인터만 생성 가능하다.
//Character* ptr;(O)
class Character
{
public:
	// 앞에 virtual을 붙여 가상함수: 동적바인딩이 됨(run-time때 호출함수 결정)
	//순수 가상함수: 자식을 위해 틀만 만드는 함수
	//자식 클래스에서 반드시 오버라이딩을 해야한다.
	virtual void attack() 
	{
		cout << "기본공격"<<endl;
	}
	virtual ~Character() //반드시 가상소멸자를 정의해야함. 이렇게 해야 자식까지 제거
	{
		cout << "~부모(Character) 소멸자" << endl;
	}
};
class Warrior : public Character
{
public:
	void attack() override //생략해도 되나, 누구나 오버라이딩을 햇다는걸 알수잇게 표시하는게 권장됨.
	{
		cout << "칼 휘두르기" << endl;
	}
	~Warrior() override
	{
		cout << "~자식(전사) 소멸자 사망" << endl;
	}
};
class Archer : public Character
{
public:
	void attack() override
	{
		cout << "화살 발싸" << endl;
	}
	~Archer() override
	{
		cout << "~자식(아처) 사망" << endl;
	}
};
class Mage : public Character
{
public:
	void attack() override
	{
		cout << "마법 발싸" << endl;
	}
	~Mage() override
	{
		cout << "~자식(마법사) 사망" << endl;
	}
};
int main()
{
	//부모의 포인터 변수 3개 생성
	Character* party[3];

	//부모의 포인터로 자식개체 생성함.
	party[0] = new Warrior;
	party[1] = new Archer;
	party[2] = new Mage;

	cout << "=================전투 시작=================\n";

	for (int i = 0; i < 3; i++)
		party[i]->attack();

	for (int i = 0; i < 3; i++)
		delete party[i];
	return 0;
}