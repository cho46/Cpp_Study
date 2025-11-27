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
	////첫번째로 중복되지 않는 인덱스 뽑기
	//unordered_map<char, int>freq;
	//string input;
	//cout << "문자열 입력 : ";
	//getline(cin, input);

	//for (const auto& el : input)
	//{
	//	freq[el]++;
	//}

	////중복되지 않은 문자 찾기(freg[index] = 1)
	//for (int i = 0;i<input.length();i++)
	//{
	//	if (freq[input[i]] == 1)
	//	{
	//		cout << "첫번째로 중복되지 않는 인덱스는 [" << i << "]입니다.";
	//		break;
	//	}
	//}

	////첫번째로 중복되는 인덱스 뽑기
	//unordered_map<char,int>freq; //중복체크
	//string input;
	//cout << "문자열 입력 : ";
	//getline(cin, input);

	//for (const auto& el : input)
	//{
	//	freq[el]++;
	//}

	////중복되지 않은 문자 찾기(freg[index] = 1)
	//for (int i = 0; i < input.length(); i++)
	//{
	//	if (freq.count(input[i]))
	//	{
	//		cout << "첫번째로 중복되는 인덱스는 [" << i << "]입니다.";
	//		break;
	//	}
	//	freq[input[i]] == 1;
	//}
	unordered_set<char> freq;

	string input;
	cout << "문자열 입력 : ";
	getline(cin, input);

	//중복되지 않은 문자 찾기(freg[index] = 1)
	for (int i = 0; i < input.length(); i++)
	{
		if (freq.count(input[i]))
		{
			cout << "첫번째로 중복되는 인덱스는 [" << i << "]입니다.";
			break;
		}
		/*freq[input[i]] == 1;*/
		freq.insert(input[i]);
	}

	return 0;
}