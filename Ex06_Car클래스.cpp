#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Car
{
public:
	Car(string _maker, string _name, int _fuel)
	{
		maker = _maker;
		name = _name;
		fuel = _fuel;
	}
	void print();
	void drive(int drive);
	void refuel(int add);
	void setMaker(string m);
	void setName(string n);
	void setFuel(int f);
	string getMaker();
	string getName();
	int getFuel();
private:
	string maker, name;
	int fuel;
};
int main()
{
	//제조사, 차종, 현재 연료량(리터단위)
	Car c1("현대", "소나타", 10);
	Car c2("테슬라", "Model3", 5);


	cout << "\n현재상태\n";
	c1.print(); //제조사, 차종, 현재 연료량
	c2.print();

	cout << " \n\n주행 중..\n";
	c1.drive(7); //7km 주행했습니다. 남은 연료는 _입니다.
	c2.drive(10);  //연료부족. __km까지 주행 가능합니다.


	cout << "\n\n주유 테스트...\n";
	c2.refuel(15); //__리터 주유 완료 __km까지 주행 가능합니다.
	c2.drive(10);

	cout << "\n\n현재상태\n";
	c1.print(); //제조사, 차종, 현재 연료량
	c2.print();

	return 0;
}

void Car::print()
{
	cout << "제조사: " << maker << " 차종: " << name << " 현재 연료량: " <<fuel<< endl;
}

void Car::drive(int drive)
{
	if (fuel < drive)
		cout <<name<<" " << "연료부족. " << fuel << "km까지 주행 가능합니다." << endl;
	else
	{
		fuel -= drive;
		cout <<name<<" " << drive << "km 주행했습니다. 남은 연료는 " << fuel << "km입니다." << endl;
	}
}

void Car::refuel(int add)
{
	fuel += add;
	cout <<name<<" " << add << "L 주유완료. " << fuel << "만큼 주행 가능합니다." << endl;
}

void Car::setMaker(string m)
{
	maker = m;
}

void Car::setName(string n)
{
	name = n;
}

void Car::setFuel(int f)
{
	fuel = f;
}

string Car::getMaker()
{
	return maker;
}

string Car::getName()
{
	return name;
}

int Car::getFuel()
{
	return fuel;
}


