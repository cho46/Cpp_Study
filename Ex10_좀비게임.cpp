#include <iostream>
#include <string>
#include <functional>
#include <forward_list>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::function;
using std::forward_list;
using std::vector;

struct Survivor
{
	string name;
	int health;
};

class ZombieGame
{
public:
	ZombieGame() : running(true)
	{
		//게임 참여자 기본적으로 3명으로 스타트
		survivors.push_front({ "나길동", 100 });
		survivors.push_front({ "차길동", 100 });
		survivors.push_front({ "고길동", 100 });

		std::srand(static_cast<unsigned>(time(nullptr)));
	}
	void run()
	{
		while (running)
		{
			std::system("cls");
			cout << "==============================\n";
			cout << "     좀비 생존 시뮬레이터                  \n";
			cout << "==============================\n";

		
			cout << "\n1. 생존자 추가\n";
			cout << "2. 랜덤 좀비 공격\n";
			cout << "3. 생존자 휴식\n";
			cout << "4. 생존자 제거\n";
			cout << "5. 생존자 목록보기\n";
			cout << "0. 게임 종료\n";

			cout << "\n메뉴 선택: ";
			int choice;
			bool checker = false;
			string finder;
			cin >> choice;
			switch (choice)
			{
			case 1:
				addSurvivor();
				break;
			case 2:
				zombieAttack();
				break;
			case 3:
				healSurvivor();
				break;
			case 4:
				cout << "삭제할 생존자를 입력하세요.";
				cin >> finder;
				if (deleteSurvivor(finder))
				{
					survivors.remove_if([finder](const Survivor& user) {return user.name == finder; });
					cout << "해당 생존자를 제거하였습니다\n";
				}
				else
					cout << "해당 생존자를 찾지 못했습니다\n";
				break;
			case 5:
				displaySurvivor();
				break;
			case 0:
				running =false;
				break;
			}
			if (survivors.empty())
			{
				cout << "모든 생존자 사망.\n";
				break;
			}
			cout << "\n\n\t\t";
			system("pause");

		}

		cout << "\n\n\t\t좀비 게임을 종료합니다.\n";
	}
private:
	void addSurvivor()
	{
		cout << "\n\n생존자를 입력 하세요 : ";
		string name;
		cin >> name;

		int health;
		do {
			cout << "체력을 입력하세요(1-100): ";
			cin >> health;
		} while (health < 1 || health > 100);

		survivors.push_front({ name,health });// 캐릭터를 등록
		cout << "\n\n\t\t[" << name << "] 생존자를 추가했습니다.\n";
	}
	void zombieAttack()
	{
		if (survivors.empty())
		{
			cout << "남은 생존자가 없습니다.\n";
			return;
		}
		for (auto& person : survivors)
		{
			int damage = rand() % 30 + 10; //10부터 30
			person.health -= damage; //체력 감소

			if (person.health < 0) person.health = 0;

			cout << " \n\n\t\t[" << person.name << "] 이(가) (" << damage << ")의 피해를 입었습니다."
				<< "=> 남은 체력 : " << person.health << endl;
		}
		//체력이 0인 사망자는 리스트 제거
		survivors.remove_if([](const Survivor& user) {return user.health <= 0; });
	}
	void healSurvivor()
	{
		if (survivors.empty())
		{
			cout << "남은 생존자가 없습니다.\n";
			return;
		}
		cout << "생존자 전원이 회복을 하였습니다.\n";
		for (auto& person : survivors)
		{
			int heal = 30;
			person.health += heal; //체력 감소

			if (person.health > 100) person.health = 100;
		}
		displaySurvivor();
	}
	bool deleteSurvivor(string finder)
	{
		for (auto& person : survivors)
			if (person.name == finder)
				return true;
			else
				return false;
		
	}
	void displaySurvivor()
	{
		system("cls");
		cout << "==============================\n";
		cout << "     생존자 리스트                  \n";
		cout << "==============================\n";
		for (auto& person : survivors)
		{
			cout << "이름 : [" << person.name << ", 남은 체력: " << person.health << "]\n";
		}
	}
private:
	forward_list<Survivor> survivors; //생존자 리스트
	bool running;
};



int main()
{
	ZombieGame game;
	game.run();
	return 0;
}