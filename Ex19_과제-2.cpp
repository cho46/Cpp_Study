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
	string s1, s2;
	cout << "단어 1 입력: ";
	cin >> s1;
	cout << "단어 2 입력: ";
	cin >> s2;
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());

	if (s1 == s2)
		cout << "두 단어는 애너그램입니다.";
	else
		cout << "두 단어는 애너그램이 아닙니다.";
	return 0;
}