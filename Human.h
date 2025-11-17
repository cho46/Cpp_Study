#pragma once
#include <string>
class Human
{
public: //어디서든 접근
	Human();
	Human(std::string _name, int _age);
	Human(const Human& other);
	~Human();

public:
	inline std::string getName() const { return name; }
	inline int getAge() const { return age; }
	std::string toString();

public:
	inline void setName(std::string _name) { name = _name; }
	inline void setAge(int _age) { age = _age; }

protected: //자신의 클래스 + 상속된 클래스
	std::string name;
	int age;

private: //자신의 클래스
};