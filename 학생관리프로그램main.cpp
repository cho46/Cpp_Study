#include <iostream>
#include "StudentContainer.h"

using std::cin;
using std::cout;
using std::endl;


void insertStudent(ScoreContainer& other)
{
	char name[10];
	int lan;
	int mat;
	int eng;

	cin.ignore();
	cout << "이름 입력: ";
	cin.getline(name, 10);

	cout << "국어 성적 입력: ";
	cin >> lan;

	cout << "수학 성적 입력: ";
	cin >> mat;

	cout << "영어 성적 입력: ";
	cin >> eng;

	other.addScore(name, lan, mat, eng);
}
int main()
{
	ScoreContainer sc;
	while (1)
	{
		cout << "\n\n\t\t* 학생관리 프로그램 *\n";
		cout << "\t\t1. 학생 등록\n";
		cout << "\t\t2. 학생 리스트\n";
		cout << "\t\t3. 학생 찾기\n";
		cout << "\t\t4. 학생 총 평균\n";
		cout << "\t\t5. 최고 점수 학생의 평균\n";
		cout << "\t\t6. 최저 점수 학생의 평균\n";
		cout << "\t\t0. 프로그램 종료\n";

		cout << "\t\t메뉴선택: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			insertStudent(sc);
			break;
		case 2:
			sc.displayScore();
			break;
		case 3:
			char find[10];
			cout << "찾을 학생의 이름 입력: ";
			cin.ignore();
			cin.getline(find, 10);
			sc.searchStudent(find);
			break;
		case 4:
			sc.averageScore();
			break;
		case 5:
			cout << "최고 학생의 성적 평균(이름은 익명입니다.)\n";
			cout<<sc.highScore();
			break;
		case 6:
			cout << "최저 학생의 성적 평균(이름은 익명입니다.)\n";
			cout<<sc.lowScore();
			break;
		case 0:
			return 0;
		}
		cout << "\n\n\t\t";
		std::system("pause");
		std::system("cls");
	}
}