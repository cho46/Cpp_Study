#include <iostream>
#include <string>
#include <unordered_map> 
#include <algorithm>
#include<cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

int main()
{
	unordered_map<string, int> map;
	while (true)
	{
		string op;
		cout << "\n\n명령어(add, modify, find, erase, print, exit)를 입력하세요\n";
		cin >> op;
		
		for (auto& ch : op)
			ch = tolower(ch);

		if (op == "add")
		{
			string name;
			int sc;
			cout << "이름과 점수를 입력하세요";
			cin >> name >> sc;

			if (map.count(name))
			{
				cout << "이미 존재하는 이름입니다\n";
				break;
			}
			map[name] = sc;
			cout << name << "학생이 추가되었습니다.\n";
		}
		else if (op == "modify")
		{
			string name;
			cout << "수정할 이름을 입력하세요: ";
			cin >> name;

			if (map.count(name))
			{
				//있을때 수정
				cout << "수정할 점수를 입력하세요: ";
				int sc;
				cin >> sc;
				map[name] = sc;
			}
		}
		else if (op == "find")
		{
			string name;
			cout << "검색할 이름을 입력하세요: ";
			cin >> name;
			
			auto it = map.find(name);

			if (it != map.end())
			{
				cout << "검색한 " << name << "의 점수는 " << it->second << "입니다.\n";
			}
			else
			{
				cout << "검색한 학생은 존재하지 않습니다.\n";
			}
		}
		else if (op == "erase")
		{
			string name;
			cout << "삭제할 이름을 입력하세요: ";
			cin >> name;
			
			if (map.erase(name))
				cout << "삭제성공\n";
			else
				cout << "삭제 실패\n";
		}
		else if (op == "print")
		{
			cout << "-------전체 학생 출력-------\n";
			for (auto el : map)
				cout << "이름: " << el.first << " , 점수: " << el.second << endl;
			cout << endl;
		}
		else if (op == "exit")
		{
			return 0;
		}
		else
		{
			cout << "올바른 명령어가 아닙니다.\n";
		}
	}
	return 0;
}