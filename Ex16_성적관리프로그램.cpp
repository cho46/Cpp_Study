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

class Students
{
public:
	Students(){}
	void addStudent()
	{
		system("cls");
		cout << "\n\n\t\t===학생추가===\n\n";
		ScoreInfo score;
		cout << "학생 이름 입력: ";
		cin >> name;
		if (student.find(name) != student.end())
		{
			cout << "이미 존재하는 이름의 학생입니다.\n";
			return;
		}
		cout << "국어 성적 입력: ";
		cin >> score.kor;

		cout << "영어 성적 입력: ";
		cin >> score.eng;

		cout << "수학 성적 입력: ";
		cin >> score.mat;

		student[name] = score;
	}
	void searchStudent()
	{
		system("cls");
		cout << "\n\n\t\t===학생정보검색===\n\n";
		string finder;
		cout << "검색할 학생 이름을 입력하세요 : ";
		cin >> finder;

		auto findcatcher = student.find(finder);
		if (findcatcher != student.end())
		{
			double total = findcatcher->second.kor + findcatcher->second.mat + findcatcher->second.eng;
			double average = (findcatcher->second.kor + findcatcher->second.mat + findcatcher->second.eng) / 3;
			cout << "해당 학생을 찾았습니다 해당 학생의 성적을 표시합니다.\n\n";
			cout << "이름 : " << findcatcher->first << " , 국어: " << findcatcher->second.kor << " , 수학: " << findcatcher->second.mat << " , 영어: " << findcatcher->second.eng
				<< " , 총점 : " << total << " , 평균: " << average << endl;
		}
		else
			cout << "해당학생은 존재하지 않습니다.\n";
	}
	void displayStudent()
	{
		system("cls");
		cout << "\n\n\t\t===학생정보 출력===\n\n";
		for (auto el : student)
		{
			double total = el.second.kor + el.second.mat + el.second.eng;
			double average = (el.second.kor + el.second.mat + el.second.eng) / 3;
			cout << "이름 : " << el.first << " , 국어: " << el.second.kor << " , 수학: " << el.second.mat << " , 영어: " << el.second.eng 
				<< " , 총점 : " << total << " , 평균: " << average<<endl;
		}
	}
	void editStudent()
	{
		system("cls");
		cout << "\n\n\t\t===학생정보 수정===\n\n";
		string finder;
		cout << "검색할 학생 이름을 입력하세요 : ";
		cin >> finder;

		auto findcatcher = student.find(finder);
		if (findcatcher != student.end())
		{
			cout << "해당 학생을 찾았습니다! ";
			cout <<"해당 학생의 성적을 우선 표시합니다.\n" << "이름 : " << findcatcher->first << " , 국어: " << findcatcher->second.kor << " , 수학: " 
				<< findcatcher->second.mat<< " , 영어: " << findcatcher->second.eng<<endl;
			cout << "어느 과목의 점수를 수정하시겠습니까 ? (1: 국어, 2 : 수학, 3 : 영어)";
			int edit;
			int eScore;
			cin >> edit;
			cout << "수정할 점수를 입력해주세요: ";
			cin >> eScore;
			switch (edit)
			{
			case 1:
				findcatcher->second.kor = eScore;
				break;
			case 2:
				findcatcher->second.mat = eScore;
				break;
			case 3:
				findcatcher->second.eng = eScore;
				break;
			}
			cout << "수정완료. ";
		}
		else
			cout << "해당학생은 존재하지 않습니다. 등록 후 사용해주세요.\n";
	}
	void deleteStudent()
	{
		system("cls");
		cout << "\n\n\t\t===학생삭제===\n\n";
		string finder;
		cout << "검색할 학생 이름을 입력하세요 : ";
		cin >> finder;

		auto findcatcher = student.find(finder);
		if (findcatcher != student.end())
		{
			cout << "해당 학생을 찾았습니다 삭제를 완료하였습니다.\n\n";
			student.erase(findcatcher);
		}
		else
			cout << "해당학생은 존재하지 않습니다.\n";
	}
	~Students() { }
private:
	string name;
	map<string, ScoreInfo> student;
};
int main()
{
	Students school;
	while (true)
	{
		system("cls");
		cout << "\n\n 성적관리 시스템\n";
		cout << "1. 학생 추가\n";
		cout << "2. 학생 검색\n";
		cout << "3. 학생 명단 출력\n";
		cout << "4. 학생 정보 수정\n";
		cout << "5. 학생 제거\n";
		cout << "0. 프로그램 종료\n";

		cout << "\n메뉴 선택: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			school.addStudent();
			break;
		case 2:
			school.searchStudent();
			break;
		case 3:
			school.displayStudent();
			break;
		case 4:
			school.editStudent();
			break;
		case 5:
			school.deleteStudent();
			break;
		case 0:
			return 0;
		}
		cout << "\n\n\t\t";
		system("pause");
	}
	return 0;
}
/*map을 이용한 학생 성적관리 프로그램을 작성
1. map<string, ScoreInfo>scores;
key:이름, value: ScoreInfo(국어,영어 수학)

2. 학생 추가 시 중복 이름은 저장할 수 없다.
3. 학생 검색시 이름을 입력받아 해당 학생의 [학생이름과목 점수, 총점, 평균] 출력
4. 학생목록 출력 시, [이름,과목 점수, 총점, 평균] 출력
5. 학생 점수 수정 시 이름을 입력 받아 국어/수학/영어 중 수정할 항목을 선택, 과목점수를 수정
6. 학생 삭제시, 이름을 입력받아 삭제
*/
