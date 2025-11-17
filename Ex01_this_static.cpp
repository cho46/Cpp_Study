#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::string;




//좌표관리 클래스
class Point
{
public:
	Point() : x(0), y(0) { ++count; }
	Point(int _x, int _y) : x(_x), y(_y) { ++count; }

	inline int getX() const
	{
		//this->x = -99999 error: 상수화된 메서드에서는 instance variable의 수정이 불가능
		return this->x;
	}
	inline int getY() const
	{
		return this->y;
	}
	inline void setX(int x)
	{
		this->x = x;
	}
	inline void setY(int y)
	{
		this->y = y;
	}
	double getDistance(const Point& other) const
	{
		int disX = (other.x - this->x);
		int disY = (other.y - this->y);
		return sqrt((disX * disX) + (disY*disY));
	}
	//정적메서드: 클래스명으로 호출 가능
	//정적메서드는 상수화 시킬 수 없음.
	static int getCount()
	{
		return count;
	}
private:
	//컴파일 타임이 정해짐.
	static constexpr int DummySize = 100;
	//enum {DummySize = 50}; //열거형을 이용한 상수값을 지정
	int dummy[DummySize];
	int x, y;
	//정적변수는 static키워드를 써서 선언한 변수를 말한다.
	//main함수가 실행되기 전 딱 한번 메모리가 할당되어 초기화한다.
	//instanc생성시 할당되는 변수가 아니다.
	//static키워드는 선언부에만 쓴다.
	static int count;
};

int Point::count = 0;

int Point::getCount()
{
	//정적멤버는 this키워드도 쓸 수 없다.
	//x = 55; error: 정적멤버는 instance variable에 접근 불가.
	return count; 
}

int main()
{
	//정적멤버는 인스턴스 생성 전에 호출이 가능!
	Point p1, p2(2, -8), p3(-33, 128);

	cout << "생성된 좌표의 개수는 " << Point::getCount() << "개 입니다.\n";

	cout << "p1(" << p1.getX() << ", " << p1.getY() << ")\n";
	cout << "p2(" << p2.getX() << ", " << p2.getY() << ")\n";
	cout << "p3(" << p3.getX() << ", " << p3.getY() << ")\n";

	cout << "p2와 p3의 거리는 " << p2.getDistance(p3) << "입니다. ";
	cout << "p3와 p1의 거리는 " << p3.getDistance(p1) << "입니다. ";

	return 0;
}