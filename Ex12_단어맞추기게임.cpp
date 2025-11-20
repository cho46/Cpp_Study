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
	map<string, string> words = {
		//key,value
		{"사과","apple"},
		{"바나나","banana"},
		{"오렌지","orange"},
		{"딸기","strawberry"},
		{"배","pear"},
		{"망고","mango"}
	};

	int correct = 0;
	cout << "\n * 단어 맞추기 게임 *\n";

	//순서대로 한글 단어가 출제되면, 그 단어에 해당하는 영단어를 입력 받는다.
	//입력 받은 영단어와 value의 값이 같으면 정답!, 다르면 오답
	string input;

	for (const auto& word : words)
	{
		cout << word.first << "를 영어로 하면? ";
		cin >> input;
		if (word.second == input)
			++correct;
		else
			cout << "오답입니다. 정답은 " << word.second << "입니다.\n";
	}

	cout << "최종점수는 " << correct * 10 << "점(60점만점) 입니다.\n";

	return 0;
}