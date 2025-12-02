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
	vector<int> v1 = { 1,2,3,1,4,3,5 };
	vector<int> v2 = { 2,2,3 };
	

	unordered_set<int> s1(v1.begin(),v1.end());
	unordered_set<int> s2(v2.begin(), v2.end());
	unordered_set<int> inter;


	for (auto el : s1)
	{
		if (s2.count(el) !=0)
			inter.insert(el);
	}
	cout << "교집합 정수: ";

	for (auto el : inter)
		cout << el<<" ";

	return 0;
}