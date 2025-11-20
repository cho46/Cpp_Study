#include <iostream>
#include <string>
#include <map> 
//red,black tree(삽입, 삭제, 검색성능이 o(logN))
//{key-value}의 쌍을 정렬된 구조로 저장한다.
//key값을 기준으로 정렬된다.
//key 중복될 수 없다.

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main()
{
	map<string, int> students;

	//삽입
	//key: 이름, value: 점수
	students["나길동"] = 85;
	students["차길동"] = 33;
	students["아길동"] = 66;
	students["고길동"] = 100;
	students["사길동"] = 24;
	students["하길동"] = 72;
	//중복값이 존재하는경우, 아무일도 하지않음
	students.insert({ "신민아",50 });
	students.insert({ "신민아",0 });


	//수정 => key가 존재하는 경우 덮어쓰기
	students["차길동"] = 0;

	for (auto student : students)
		cout << student.first << " = " << student.second << endl;

	//[] 접근시 key가 없는 경우 기본값을 리턴 => 푸길동 = 0점으로 생성
	cout << "사길동점수 = " << students["푸길동"] << endl;
	//at는 key가 없는 경우 out_of_range 발생!
	cout << "사길동점수 = " << students.at("푸길동") << endl;


	auto itFind = students.find("고길동"); //고길동의 위치를 Iterator로 리턴

	if (itFind != students.end())
		cout << "고길동은 존재합니다.\n";
	else
		cout << "찾는 값은 존재하지 않습니다.\n";

	//범위 검색
	auto itBegin = students.lower_bound("나길동"); //"나길동" 이상 =>"나길동"이 있는 Iterator리턴
	auto itEnd = students.upper_bound("차길동"); //"차길동" 초과 => "나길동" Iterator리턴
	
	cout << "\n범위 검색\n\n";
	for (auto it = itBegin; it != itEnd; it++)
		cout << it->first << "=" << it->second << endl;


	return 0;
}