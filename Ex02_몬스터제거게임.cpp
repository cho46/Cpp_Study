#include <iostream>
#include "ConsoleUtils.h"
#include <string>
#include <stdlib.h>
#include<time.h>
#include <conio.h> // 키보드 입력 _kbhit, _getch(): 에코 기능X(받기만 하고 안써짐.)

using std::cout;
using std::cin;
using std::endl;
using std::string;
#pragma warning (disable:4996)
//캐릭터의 정보를 저장하는 캐릭터 클래스
class Character
{
public:
	Character(string name = "unknown", int x = 0, int y = 0, char icon = '?') : name(name), x(x), y(y), icon(icon)
	{
	}
	Character(const Character& other) : Character(other.name + "_clone",other.x,other.y,other.icon)
	{
	}
	void Move(char input, int width, int height)
	{
		switch (input)
		{
		case 'w':case 'W': 
			if(y>0) 
				--y;
			break;
		case 's' : case 'S':
			if(y<height -1)
				++y;
			break;
		case 'a' : case 'A':
			if (x > 0) 
				--x;
			break;
		case 'd' : case 'D':
			if (x < width - 1)
				++x;
			break;
		}
	}
	
	void Draw(char **map)
	{
		map[y][x] = icon;
	}
public:
	inline int GetX() const{ return x; }
	inline int GetY() const { return y; }
	inline string GetName() const{ return name; }

private:
	int x, y;				//좌표(X: 행, Y: 열)
	string name;		//캐릭터 이름
	char icon;			//몬스터:M, 히어로: H
};

// 아이템 클래스-------------------------------------------------------------------------------------------------------------------------------------------
class Item
{
public:
	Item(int x = 0, int y = 0, char icon = 'I') : x(x),y(y),icon(icon),active(true)
	{
		
	}
	inline int GetX() { return x; }
	inline int GetY() { return y; }
	inline bool IsActive() { return active; }
	
	void DeActivate() { active = false; }
	void Draw(char** map)
	{
		if(active)
			map[y][x] = icon;
	}
private:
	int x, y;			//좌표
	char icon;		//아이콘 : 아이템은 I
	bool active;		//생존여부
};
// 게임진행 클래스-------------------------------------------------------------------------------------------------------------------------------------------
class GameManager
{
public:
	void SetPlayer(const Character& other)
	{
		player = other;
	}
public:
	GameManager(): move(0), monsterCount(MaxMonster)
	{
		//맵 생성(2차원 배열 생성)
		map = new char* [Height];
		for (int i = 0; i < Height; i++)
		{
			map[i] = new char[Width];
		}
		struct Point { int x, y; };

		//구조체 변수에 차례대로 좌표 저장
		int index = 0;
		Point position[Width * Height-1]; //좌표를 저장하기 위한 배열 생성

		for (int i = 0; i < Height; i++) //행 좌표
		{
			for (int j = 0; i < Width; j++) //열 좌표
			{
				if (i == Height / 2 && j == Width / 2)
				{
					continue;
				}
				position[index].x = j;
				position[index].y = i;
				++index;
			}
		}

		//피셔-에이츠 셔플 방식으로 좌표 섞기
		std::srand((unsigned int)time(NULL));
		for (int i = index - 1; i > 0; i--)
		{
			
			int index = std::rand()%(i+1);
			std::swap(position[i],position[index]);
		}
		//몬스터 초기화
		int cIdx = 0;
		for (int i = 0; i < MaxMonster; i++)
		{
			//임시객체로 생성
			monsters[i] = Character("Monster_" + std::to_string(i + 1), position[cIdx].x, position[cIdx].y, 'M');
			monsterAlive[i] = true;
			++cIdx;
		}
		for (int i = 0; i < MaxItem; i++)
		{
			items[i] = Item(position[cIdx].x, position[cIdx].y);
			++cIdx;
		}

	}
	~GameManager()
	{
		for (int i = 0; i < Height; i++)
		{
			delete[] map[i];
		}
		cout << "2차원 맵(" << Height << " * " << Width << "제거\n";
		delete[] map;
		cout << "2차원 배열의 포인터 제거\n";
	}
	void Run()
	{
		HideCursor();
		while (true)
		{//맵 설정
			SetMap();
			displayMap();
			if (_kbhit())//키보드 입력이 있다면
			{
				char input = _getch(); //입력받은 값을 저장
				if (input == 'q')
					return; //함수종료
				player.Move(input, Width, Height);

				checkMonster(); //몬스터와의 충돌여부
				checkItem(); //아이템과 충돌여부

			}
			if (monsterCount == 0)
			{
				SetMap();
				displayMap();
				cout << "\n\n\t\t축하합니다. 모든 몬스터를 제거했습니다.";
				cout << "획득한 스코어는 [" << score << "]점 입니다";
				return;
			}
		}
	}
public:
	static const int Width = 20;
	static const int Height = 10;
	static const int MaxMonster = 10;
	static const int MaxItem = 3;

private:
	char** map; //2차원 배열의 주소를 저장
	Character monsters[MaxMonster];															//몬스터
	bool monsterAlive[MaxMonster];			//몬스터 생존여부
	int monsterCount;																//몬스터 개수
	int score;																								//점수: 몬스터+10,아이템+5
	Character player;																						//플레이어
	Item items[MaxItem];																				//아이템

private:
	void SetMap()
	{
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				map[i][j] = ' . ';
			}
		}
		//몬스터 표시
		for (int i = 0; i < MaxMonster; i++)
		{
			if(monsterAlive[i])
				monsters[i].Draw(map);
			//cout << "1";
		}
		//아이템 표시
		for (int i = 0; i < MaxItem; i++)
		{
			items[i].Draw(map);
			//cout << "2";
		}
		//플레이어 표시
		player.Draw(map);
		//cout << "3";
	}
	void displayMap()
	{
		GotoXY(0, 0);
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				cout << map[i][j];
			}
			cout<<endl;
		}
		cout << "\n\n\n점수:[" << score << "]점 남은 몬스터: " << monsterCount << "]마리\n";
		cout << "w: 위, s: 아래, a: 왼쪽, d: 오른쪽, q: 종료\n";
	}
	void checkMonster()
	{
		for (int i = 0; i < MaxMonster; i++)
		{
			if (monsterAlive[i])
			{
				if (monsters[i].GetX() == player.GetX() && monsters[i].GetY() == player.GetY())
				{
					cout << "장애물과 충돌하였습니다 게임을 종료합니다.";
					return;
				}
			}
		}
	}
};

int main()
{
	//GotoXY(10, 3);
	//cout << "Hello World";
	//
	////HideCursor();
	//for (int i = 0; i < 20; i++)
	//{
	//	GotoXY(i*2, 5);
	//	cout << i + 1;
	//	Sleep(500);
	//}
	Character h1("Hero_1", GameManager::Width / 2, GameManager::Height / 2, 'H');
	GameManager game;
	//game.SetPlayer(h1); // 등록

	////게임시작
	//game.Run();
	

	return 0;
}