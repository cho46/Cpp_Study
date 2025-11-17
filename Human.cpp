#include "Human.h"
#include <iostream>
Human::Human() : name("아무개"),age(1)
{
	std::cout << "Human 기본 생성자\n";
}

Human::Human(std::string _name, int _age)
{
	name = _name;
	age = _age;
	std::cout << "Human 매개변수 생성자\n";
}

Human::Human(const Human& other): name(other.name), age(other.age)
{
}

Human::~Human()
{
	std::cout << "~Human 소멸자\n";
}
std::string Human::toString()
{
	std::string s1 = "이름: " + name;
	std::string s2 = ", 나이: " + std::to_string(age);

	return s1 + s2;
}

