#pragma once
#include <iostream>
#include<cmath>
using std::cout;
using std::endl;
using std::cin;


#pragma warning (disable:4996)

class Character
{
public:
	Character() : x(0), y(0)
	{
		name = new char[8];
		strncpy(name, "unknown", 8); //strncpy를 쓰면 마지막에 크기까지 널문자 포함
		cout << "1. 기본 생성자\n" << name << endl;
	}
	//타켓 생성자
	Character(const char* na, int x, int y) : x(x), y(y)
	{
		name = new char[strlen(na) + 1];
		strncpy(name, na, strlen(na) + 1);
		cout << "2. 매개변수 생성자: " << name << endl;
	}
	//위임 생성자
	Character(const Character& other) : Character (other.name, other.x, other.y)//x(other.x), y(other.y)
	{
		/*name = new char[strlen(other.name) + 1];
		strncpy(name, other.name, strlen(other.name) + 1);
		cout << "3. 복사 생성자: " << name <<" clone" << endl;*/
	}
	~Character()
	{
		cout << "4. 소멸자" << name << endl;
		delete[] name;
	}
	double getDistance(const Character& other)
	{
		double dx = pow(other.x - this->x, 2);
		double dy = pow(other.y - this->y, 2);
		return sqrt(dx + dy);
	}
	inline void displayPosition() const
	{
		cout << "[" << name << "]의 위치(" << x << " , " << y << ")\n";
	}
	inline const char* getName() { return name; }
	inline int getX()const { return x; }
	inline int getY() const { return y; }

	inline void setName(const char* na)
	{
		if (name)
			delete[] name;

		name = new char[strlen(na) + 1];
		strncpy(name, na, strlen(na) + 1);
	}
	inline void setX(int x) { this->x = x; }
	inline void setY(int y) { this->y = y; }

private:
	char* name = nullptr; //캐릭터명
	int x = 0, y = 0; //캐릭터의 좌표
};