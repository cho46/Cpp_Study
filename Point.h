#pragma once
#include <string>
#include <iostream>
using std::cout;
using std::endl;


#pragma warning(disable:4996)

namespace myName
{
	class Point
	{
		friend Point operator+(int num, const Point& other);
	public:
		Point() : x(0), y(0) { cout << "1. 기본 생성자\n"; }
		Point(int x) : x(x), y(y) { cout << "3. 인수 1개 받는 생성자\n"; }
		Point(int x, int y) : x(x), y(y) { cout << "3. 인수 2개 받는 생성자\n"; }
		Point(const Point& other) :  x(other.x), y(other.y) { cout << "복사생성자 호출\n"; }
		~Point() { cout << "~소멸자\n"; }
		inline int getX() const { return x; }
		inline int getY() const { return y; }

		inline void setX(int x) { this->x = x; }
		inline void setY(int y) { this->y = y; }

		inline std::string getPoint() const
		{
			return "(" + std::to_string(x) + " , " + std::to_string(y) + ")";
		}

	public:
		bool operator==(const Point& other);
		void operator+=(const Point& other);
		Point& operator=(const Point& other);
		Point operator +(const Point& other);
		double operator -(const Point& other);
		Point operator++(); //전치연산
		Point operator++(int); //후치연산
		Point operator +(const int num);


	private:
		int x, y;
	};
}