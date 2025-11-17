#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;

enum Hand { SISSORS = 1, ROCK, PAPER };

class RSPGame
{
public:
	//instance varible
	int user, computer;

	void play()
	{
		char isContinue;
		do
		{
			system("cls"); //화면지우기
			user = getUserChoice();
			computer = rand() % 3 + 1; //1 ~ 3
			cout << "컴퓨터의 선택 : " << getHandChoice(computer) << endl;
			cout << "유저의 선택 : " << getHandChoice(user) << endl;

			evalResult();

			cout << "\n\n\t\t계속하려면 Y/y를 눌러주세요!: ";
			cin >> isContinue;
		} while (isContinue == 'Y' || isContinue == 'y');
	}

	void evalResult()
	{
		int compare = computer - user;

		cout << "\n\n\t\t게임 결과: ";
		if (compare == 0)
			cout << "비겼다!";
		else if (compare == -2 || compare == 1)
			cout << "컴퓨터 승!";
		else// if (compare == -1 || compare == 2)
			cout << "유저 승!";
	}

	const char* getHandChoice(int number)
	{
		switch (number)
		{
		case 1:
			return "가위";
		case 2:
			return "바위";
		case 3:
			return "보";
		default:
			return "오류";
		}
	}

	int getUserChoice()
	{
		int choice;

		do
		{
			cout << "가위(1) / 바위(2) / 보(3) 중 한개를 선택 하세요: ";
			cin >> choice;
		} while (choice < 1 || choice > 3);

		return choice;
	}
};

int main()
{
	RSPGame rsp; //instance 생성

	rsp.play();

	return 0;
}