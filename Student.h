#pragma once
#include "Human.h"
#include <string> // 써도되고 안써도됨 왜냐면 Human에 이미 포함이 되어있기 때문
class Student : public Human
{
public:
	Student();
	Student(std::string _name, int _age, std::string _no, std::string _major);
	Student(const Student& other);
	~Student();

public:
	std::string getName() const { return no; }
	std::string getMajor() const { return major; }
	std::string toString();
public:
	void setNo(std::string _no) { no = _no; }
	void setMajor(std::string _major) { major = _major; }


protected:
private:
	std::string no;
	std::string major;
};