#include <iostream>
#include <string>
#include <unordered_map> 
#include <algorithm>
#include<cctype>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;
using std::stringstream;

int main()
{
	unordered_map<string, int>words;
	string input;
	cout << "문자열 입력 : ";
	getline(cin, input);

	stringstream ss(input);
	string word;

	while (ss >> word)
	{
		words[word] = word.length();
	}
	string Shigh;
	int length = 0;
	for (auto el : words)
	{
		if (el.second > length)
		{
			Shigh = el.first;
			length = el.second;
		}
	}
	cout << "\n\n가장 점수가 높은 단어: " << Shigh << "(" << length << "점) 입니다.";
}