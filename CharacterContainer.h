#pragma once
#pragma once
#include <iostream>
#include"Character.h"

using std::cout;
using std::cin;
using std::endl;



//컨트롤 클래스
class Charatercontainer
{
public:
	~Charatercontainer()
	{
		for (int i = 0; i < index; i++)
		{
			delete p[i];
			cout << "캐릭터가 제거되었습니다. \n";
			cout << "남은 캐릭터 수: " << index - i - 1 << endl;
		}
		index = 0;
	}
	void addCharacter(const char* name, int x, int y)
	{
		if (index < CHARACTER_SIZE)
		{
			p[index++] = new Character(name, x, y); //인스턴스 생성
			cout << "[" << name << "] 캐릭터가 추가되었습니다.\n";
		}
	}
	inline int getCharacterCount() { return index; }
	void displayCharacter()
	{
		for (int i = 0; i < index; i++)
		{
			p[i]->displayPosition();
		}
	}
	void displayAllDistance() const
	{
		for (int i = 0; i < index; i++)
		{
			for (int j = i + 1; j < index; j++)
			{
				cout << p[i]->getName() << " _ " << p[j]->getName() << "의 거리는" << p[i]->getDistance(*p[j]) << endl;
			}
		}
	}

private:
	static const int CHARACTER_SIZE = 100;
	Character* p[CHARACTER_SIZE] = { nullptr }; //포인터 변수 100개
	int index = 0;
};