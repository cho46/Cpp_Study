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
	
	//vector<int> v = { 3,5,6,2,5,6,2,1,1,5,3,5,4,4 };
	//unordered_set<int> s;

	//for (auto el : v)
	//	s.insert(el);

	//cout << " - 중복제거 리스트 - \n";
	//for (auto el : s)
	//	cout << el << " ";
	//cout << endl;

	//vector<string>words = { "eat","tea","tan","ate","nat","bat" };
	//unordered_set<string> s;

	//unordered_map<string, vector<string>> anagram;
	//
	//for (auto& word : words)
	//{
	//	string temp = word;
	//	std::sort(temp.begin(), temp.end());
	//	anagram[temp].push_back(word);
	//}
	////출력
	//for (auto group : anagram)
	//{
	//	for (auto value : group.second)
	//	{
	//		cout << "value" << " ";
	//	}
	//	cout << endl;
	//}

	//가장 긴 연속 수열 찾기
	vector<int> v = { 100, 4, 200, 3, 1, 2 };
	unordered_set<int> s(v.begin(),v.end());
	vector<int> r,numsV;

	for (auto& el : v)
		s.insert(el);

	/*for (auto n : s)
		cout << n<<" ";*/

	//for (auto num : v)
	//{
	//	for (int i = 1; i <= num; i++)
	//	{
	//		if (s.count(num-i))
	//		{
	//			if (!r.count(num))
	//				r.insert(num);
	//		}
	//		else
	//		{
	//			break;
	//		}
	//	}
	//}
	//
	//for (auto len : r)
	//	cout << len << " ";

	int longestLen = -1;
	for (auto& num : s)
	{
		//1작은수가 존재하지 않는다면? 수열의 시작점
		int len, temp;
		if (s.count(num - 1) == 0)
		{
			len = 1;
			temp = num;
			r.push_back(num);
			//1큰수가 존재한다면? 그다음수가 존재하는지를 계속적으로 비교
			while (s.count(temp+1))
			{
				temp++;
				len++;
				numsV.push_back(temp);
			}
			
			if (longestLen < len)
			{
				longestLen = len;
				r = numsV;
				numsV.erase(numsV.begin(),numsV.end());
			}
		}
	}


	cout << "가장 긴 연속 수열의 길이 = "<<longestLen<<"입니다\n";
	//가장 긴 연속 수열의 길이=1,2,3,4 입니다.



	return 0;
}