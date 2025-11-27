/*
배열과 목표값 target이 주어일때 합이 target인 두 요소의 인덱스를 리턴하는 문제
목표값이 없는 경우는 {-1, -1}를 리턴함.
*/

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

//std::pair<int, int> twoSum(std::vector<int>v, int target)
//{
//	unordered_map<int, int>map;
//
//	for (int i = 0; i != v.size(); i++)
//	{
//		int need = target - v[i];
//		auto it = map.find(need);
//		if (it != map.end())
//		{
//			return { i, it->second };
//		}
//		map[v[i]] = i;
//	}
//	return { -1,-1 };
//}



int main()
{
	vector<int> v = { 2,5,7,11,15 };
	int target = 9;
	unordered_map<int, int>map;

	for (int i = 0;i !=v.size();i++)
	{
		int need = target - v[i];
		auto it = map.find(need);
		if (it != map.end())
		{
			cout << i <<" , " << it->second;
		}
		map[v[i]] = i;
	}

	//target의 합이 되는 인덱스는 0,2 입니다.
	//9 2,0
	//16 3,1
	//22 4,2
	return 0;
}
	
