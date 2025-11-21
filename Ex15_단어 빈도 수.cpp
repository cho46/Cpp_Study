#include <iostream>
#include <string>
#include <map> 
#include <sstream>
#include <cctype> //ispunc
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::stringstream;
using std::transform;

void cleanWord(string& word)
{
	//조건이 거짓인 데이터를 앞에서부터 채운 후, 조건이 참인 위치를 리턴.
	//구두점 제거
	auto it = std::remove_if(word.begin(), word.end(), [](char c) {return ispunct(c); });
	word.erase(it, word.end());

	//검색 시작위치, 검색종료위치, 기록 시작위치, 변환값
	transform(word.begin(), word.end(), word.begin(), [](char c) {return tolower(c); });
}


int main()
{
	string input;
	cout << "문자열 입력 : ";
	getline(cin, input);

	cleanWord(input);

	stringstream ss(input);
	string word;

	map<string, int> words;
	


	while (ss>>word)
	{
		/*for (auto& letter : word)
		{
			if (isupper(letter))
				letter = tolower(letter);
		}
			words[word]++;*/
		//cout << word << endl;

		words[word]++;
	}

	cout << "단어 빈도 출력\n";
	
	for (const auto& el : words)
		cout << el.first << " => " << el.second << endl;
	
	return 0;
}