#include <iostream>
using namespace std;

struct trapezoid
{
	double base, top, height;
};

void input(trapezoid *p);
void input(trapezoid &ref);
double getArea(const trapezoid* area);
double getArea(const trapezoid& area);

int main()
{

	trapezoid tra;
	//input(&tra);
	input(tra);

	cout << "사다리꼴의 넓이는" << getArea(&tra) << "입니다.";
	cout << "사다리꼴의 넓이는" << getArea(tra) << "입니다.";


	return 0;
}

void input(trapezoid* p)
{

	cout << "사다리꼴의 윗변 / 밑변 / 높이를 차례로 입력하세요";
	cin >> p->top >> p->base >> p->height;
}

void input(trapezoid& ref)
{
	cout << "사다리꼴의 윗변 / 밑변 / 높이를 차례로 입력하세요";
	cin >> ref.top >> ref.base >> ref.height;
}

double getArea(const trapezoid* area)
{
	double total = ((area->top + area->base) * area->height) / 2.0;

	return total;
}

double getArea(const trapezoid& area)
{
	double total = ((area.top + area.base) * area.height) / 2.0;

	return total;
}
