#include <iostream>
#include <string>
#include <unordered_map> 
#include <algorithm>
#include<cctype>
#include <vector>
#include <sstream>
#include <unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;
using std::stringstream;
using std::unordered_set;

int main()
{
	std::vector<string> words = { "eat", "tea", "listen", "tan", "ate", "silent", "nat", "bat" };
	unordered_map<string, std::vector<string>> anagram;
	for (auto& word : words)
	{
		string temp = word;
		std::sort(temp.begin(), temp.end());
		anagram[temp].push_back(word);
	}

	int maxlen = 0;
	 vector<string> maxString;
	for (auto group : anagram)
	{
		if (group.second.size() > maxlen)
		{
			maxlen = group.second.size();
			maxString = group.second;
		}
	}
	cout << "가장 큰 그룹은 ";
	for (auto el : maxString)
		cout << el<<" ";
	cout << "로, " << maxlen << "개의 단어가 연결되어 있습니다.";
	

	return 0;
}