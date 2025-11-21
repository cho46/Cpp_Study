#include <iostream>
#include <string>
#include <map> 


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

struct MemberInfo
{
	string phone;
	int age;
};

int main()
{
	map<string, MemberInfo> member;

	for (int i = 0; i < 5; i++)
	{
		string name;
		cout << "이름 입력: ";
		cin >> name;

		//이름 중복체크
		if (member.find(name) != member.end())

		{
			cout << "해당이름이 이미 존재합니다\n";
			i--;
			continue;
		}
		MemberInfo info;
		cout << "전화번호 입력 : ";
		cin >> info.phone;

		cout << "나이입력: ";
		cin >> info.age;

		member[name] = info;
	}

	cout << "\n * 회원 정보 리스트 *\n";
	for (const auto& el : member)
	{
		cout << "이름 : " << el.first //키
			<< ",  전화번호 : " << el.second.phone
			<< " ,  나이 : " << el.second.age<<endl;
	}
	return 0;
}