#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Employee
{
public:
	Employee(string _name, int _id, double _salary)
	{
		name = _name;
		id = _id;
		salary = _salary;
	}
	void print();
	void raiseSalary(int bonus);
	string getName();
	int getId();
	double getSalary();
	void getName(string n);
	void getId(int i);
	void getSalary(double s);

private:
	string name;
	int id;
	double salary;
};


int main()
{
						  //이름, id, 연봉
	Employee e1("홍길동", 1001, 3000.0);
	Employee e2("고길동", 1002, 4000.0);

	cout << "\n직원 정보 리스트\n";
	e1.print();
	e2.print();

	cout << "\n급여 인상\n";
	e1.raiseSalary(10); //10%인상
	e2.raiseSalary(5);

	cout << "\n인상된 급여의 직원 정보 리스트\n";
	e1.print();
	e2.print();

	return 0;
}

void Employee::print()
{
	cout << "이름: " << name << " ID : " << id << "연봉 : " << salary<<endl;
}

void Employee::raiseSalary(int bonus)
{
	salary += salary/(100/bonus);
}

string Employee::getName()
{
	return name;
}

int Employee::getId()
{
	return id;
}

double Employee::getSalary()
{
	return salary;
}

void Employee::getName(string n)
{
	name = n;
}

void Employee::getId(int i)
{
	id = i;
}

void Employee::getSalary(double s)
{
	salary = s;
}
