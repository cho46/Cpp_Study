#include <iostream>
#include <string>
#include <map> 


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

struct ScoreInfo
{
	int kor;
	int eng;
	int mat;
};


int main()
{
	string name;

	map<string, ScoreInfo> Students;

	for (int i = 1; i < 6; i++)
	{
		system("cls");
		cout << i << "번째 입력\n\n";
		cout << "학생이름 입력: ";
		cin >> name;
		if (Students.find(name) != Students.end())
		{
			cout << "이미 존재하는 학생입니다\n";
			system("pause");
			i--;
			continue;
		}
		ScoreInfo info;
		cout << "국어점수 입력: ";
		cin >> info.kor;

		cout << "수학점수 입력: ";
		cin >> info.mat;

		cout << "영어점수 입력: ";
		cin >> info.eng;

		Students[name] = info;
	}

	system("cls");
	cout << "학생 정보 출력\n";
	for (const auto& el : Students)
	{
		double average = (el.second.eng+el.second.mat+el.second.kor)/3.0;
		cout << "이름 : " << el.first << " , 국어: " << el.second.kor << " , 수학 : " << el.second.mat << " , 영어 : " << el.second.eng << " , 평균: " << average << endl;
	}
	return 0;
}