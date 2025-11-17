#include "Student.h"
#include <iostream>
#pragma warning(disable:4996)

//using std::cin;
//using std::cout;
//using std::endl;
//
//Score::Score()
//{
//	name = new char[10];
//	std::strcpy(name, "Unknown");
//	
//	lan = 0;
//	eng = 0;
//	mat = 0;
//}
//
//Score::Score(const char* name, int lan, int mat, int eng)
//{
//	this->name = new char[std::strlen(name)+1];
//	std::strcpy(this->name, name);
//	this->lan = lan;
//	this->eng = eng;
//	this->mat = mat;
//
//}
//
//Score::~Score()
//{
//	delete[] name;
//}
//
//Score::Score(const Score& other) : Score(other.name, other.lan, other.mat, other.eng) {}
//
//void Score::displayScore()
//{
//	cout << "[이름] : " << name << "\t\t[국어]: " << lan << "\t[수학]: " << mat << "\t[영어]: " << eng<<endl;
//}
//
//
//inline void Score::setName(const char* name)
//{
//	if (this->name != nullptr)
//		delete[] this->name;
//	this->name = new char[strlen(name) + 1];
//	strcpy(this->name, name);
//}
//
//inline void Score::setLan(int lan)
//{
//	this->lan = lan;
//}
//
//inline void Score::setMat(int mat)
//{
//	this->mat = mat;
//}
//
//inline void Score::setEng(int eng)
//{
//	this->eng = eng;
//}

Student::Student() :  no("12345678"), major("자율전공")
{
	std::cout << "Student 기본 생성자\n";
}

Student::Student(std::string _name,int _age, std::string _no, std::string _major)  : Human(_name),no(_no),major(_major)
{
	std::cout << "Student 매개변수 생성자\n";
}

Student::Student(const Student& other) : no(other.no), major(other.major) 
	: Human(other), no(other.no),major(other.major)
{
	std::cout << "Student 복사 생성자\n";
}

Student::~Student()
{
	std::cout << "Student 소멸자\n";
}

std::string Student::toString()
{
	std::string parentStr = Human::toString(); //이름과 나이를 리턴하는 부모의 함수 호출
	std::string s1 = ", 학번: " + no;
	std::string s2 = ", 전공: " + major;
	return parentStr + s1 + s2;
}
