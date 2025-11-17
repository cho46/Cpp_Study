#include <iostream>
using std::cout;
using std::cin;
using std::endl;

enum oPer{ROC=1,PAP, SCI};

class RPS
{
public:
	int Computer();
	int User();
	void calc(int com, int user);
};
int RPS::Computer()
{
	srand(time(NULL));
	int computer = rand() % 3+1;
	return computer;
}
int RPS::User()
{
	int user;
	cout << "°¡À§¹ÙÀ§º¸ °ÔÀÓ\n";
	cout << "¹ÙÀ§(1) / º¸(2) / °¡À§(3)\n";
	cout << "´ç½ÅÀÇ ¼±ÅÃ: ";
	cin >> user;
	return user;
}
void RPS::calc(int com, int user)
{
	switch (com)
	{
	case ROC:
		if (user == PAP)
			cout << " ÀÌ±è" << endl;
		else if (user == SCI)
			cout << " Áü" << endl;
		else
			cout << "ºñ±è" << endl;
		break;
	case PAP:
		if (user == PAP)
			cout << " ºñ±è" << endl;
		else if (user == SCI)
			cout << "ÀÌ±è" << endl;
		else
			cout << "Áü" << endl;
		break;
	case SCI:
		if (user == PAP)
			cout << "Áü" << endl;
		else if (user == SCI)
			cout << "ºñ±è" << endl;
		else
			cout << "ÀÌ±è" << endl;
		break;
	}
}


int main()
{
	char choice;
	RPS r1;
	while (1)
	{
		r1.Computer();
		r1.User();
		r1.calc(r1.Computer(), r1.User());
		cout<< "ÇÑÆÇ´õ?";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
			break;
	}
	return 0;
}