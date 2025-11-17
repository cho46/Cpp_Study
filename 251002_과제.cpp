#include <iostream>
#include <string>	//string
#include <cstdlib>	//rand, srand
#include <ctime>	//time
#include <conio.h>	//_kbhit, _getch(): 에코기능X
#include "ConsoleUtils.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

#pragma warning (disable : 4996)

//----------------------------------------------------//캐릭터의 정보 저장 클래스
class Character
{
public:
	Character(string name = "unknown", int x = 0, int y = 0, char icon = '?')
		: name(name), x(x), y(y), icon(icon)
	{
	}
	Character(const Character& other)
		: Character(other.name + "_clone", other.x, other.y, other.icon) //생성자 호출
	{
	}
	void Move(char input, int width, int height)
	{
		switch (input)
		{
		case 'w': case 'W':
			if (y > 0)
				--y;
			break;
		case 's': case 'S':
			if (y < height - 1)
				++y;
			break;
		case 'a': case 'A':
			if (x > 0)
				--x;
			break;
		case 'd': case 'D':
			if (x < width - 1)
				++x;
			break;
		}
	}

	void Draw(char** map)
	{
		map[y][x] = icon;
	}

	inline int GetX() const { return x; }
	inline int GetY() const { return y; }
	inline string GetName() const { return name; }

private:
	int x, y;		//좌표(x: 행, y: 열)
	string name;	//캐릭터 이름
	char icon;		//몬스터: M, 히어로: H
};

//----------------------------------------------------//아이템 정보 저장 클래스
class Item
{
public:
	Item(int x = 0, int y = 0, char icon = 'I')
		: x(x), y(y), icon(icon), active(true)
	{
	}

	inline int GetX() const { return x; }
	inline int GetY() const { return y; }
	inline bool IsActive() const { return active; }
	void DeActivate() { active = false; }
	void Draw(char** map)
	{
		if (active)
			map[y][x] = icon;
	}

private:
	int x, y;     //좌표
	char icon;	  //아이템: I
	bool active;  //생존 여부
};

//----------------------------------------------------//게임 진행 클래스
class GameManager
{
public:
	void SetPlayer(const Character& other)
	{
		player = other;
	}
public:
	GameManager() : score(0), monsterCount(MaxMonster)
	{
		//맵 생성(2차원 배열 생성)
		map = new char* [Height]; //포인터 배열 생성
		for (int i = 0; i < Height; i++)
		{
			map[i] = new char[Width];
		}

		//좌표 저장하기 위한 구조체 생성
		struct Point { int x, y; };
		Point position[Width * Height - 1]; //좌표를 저장하기 위한 배열 선언		

		//구조체 변수에 차례대로 좌표 저장
		int index = 0;
		for (int i = 0; i < Height; i++) //행 좌표
		{
			for (int j = 0; j < Width; j++) //열 좌표
			{
				if (i == Height / 2 && j == Width / 2) //중앙좌표 값
				{
					continue;
				}
				position[index].x = j;
				position[index].y = i;
				++index;
			}
		}

		//피셔 - 에이츠 셔플 방식으로 좌표 섞기
		std::srand((unsigned int)time(NULL));
		for (int i = index - 1; i > 0; i--)
		{
			int index = std::rand() % (i + 1);
			std::swap(position[i], position[index]);
		}

		//몬스터 초기화
		int cIdx = 0;
		for (int i = 0; i < MaxMonster; i++)
		{
			//임시 객체 생성해서 대입
			monsters[i] = Character("Monster_" + std::to_string(i + 1), position[cIdx].x, position[cIdx].y, 'O');
			monsterAlive[i] = true;
			++cIdx;
		}
	}

	~GameManager()
	{
		for (int i = 0; i < Height; i++)
		{
			delete[] map[i];
		}
		cout << "2차원 맵(" << Height << " *  " << Width << ")제거\n";

		delete[] map;
		cout << "2차원 배열의 포인터 제거\n";
	}

	void Run()
	{
		HideCursor();
		while (true)
		{
			//맵 설정
			SetMap();
			DisplayMap();

			if (_kbhit()) //키보드 입력이 있다면?
			{
				char input = _getch(); //입력 받은 값을 저장

				if (input == 'q')
					return; //함수 종료

				player.Move(input, Width, Height);
				if(score<29)
				++score;
				else
				{
					cout << "\n\n이동 최대 횟수를 초과했습니다.게임을 종료합니다\n\n";
					return;
				}
				if (CheckMonster())
					return;
			}

			if (player.GetX()==19)//통과
			{
				SetMap();
				DisplayMap();
				cout << "\n\n\t\t축하합니다!\n";
				cout << "\t\t획득한 점수는 [" << (30 - score + 1) * 10 << "]점 입니다.\n\n";
				return;
			}
		}
	}
private:
	bool CheckMonster()
	{
		for (int i = 0; i < MaxMonster; i++)
		{
			if (monsterAlive[i])
			{
				if (monsters[i].GetX() == player.GetX() && monsters[i].GetY() == player.GetY())
				{
					cout << "장애물과 충돌하였습니다. 게임을 종료합니다.\n";
					return true;
				}
			}
		}
		return false;
	}

	void SetMap()
	{
		//맵을 '.'으로 초기화
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				map[i][j] = '.';
			}
		}

		//몬스터 표시
		for (int i = 0; i < MaxMonster; i++)
		{
			if (monsterAlive[i])
				monsters[i].Draw(map);
		}

		//플레이어 표시
		player.Draw(map);
	}

	void DisplayMap()
	{
		GotoXY(0, 0);
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}

		cout << "\n\n남은 이동횟수:[" << 30-score << "]회 현재 점수: [" << (30-score+1)*10 << "]점\n";
		cout << "w: 위, s: 아래, a: 왼쪽, d: 오른쪽, q: 종료\n";
	}
	public:
		static const int Width = 20;
		static const int Height = 5;
		static const int MaxMonster = 15;
private:
	char** map; //2차원배열의 주소 저장
	Character monsters[MaxMonster];	//몬스터 5마리
	bool monsterAlive[MaxMonster];  //몬스터 생존여부
	int monsterCount;			    //살아있는 몬스터 개수
	int score;						//몬스터: 10점+, 아이템: 5점+
	Character player;				//플레이어(히어로)
};


//----------------------------------------------------//main
int main()
{
	Character h1("Hero_1", 0, 2, 'P');
	GameManager game;
	game.SetPlayer(h1); //플레이어 등록!
	game.Run(); //게임 시작!

	return 0;
}