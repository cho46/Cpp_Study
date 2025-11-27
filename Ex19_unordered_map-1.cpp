#include <iostream>
#include <string>
#include <unordered_map> 
#include <algorithm>
#include<cctype>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;

int main()
{
	vector<int> numbers = { 2,1,1,3,4,1,5,5,9,1,3 };
	unordered_map<int, int>counters;
	for (auto el : numbers)
		counters[el]++;


	for (auto el : counters)
		cout << el.first << " => " << el.second << "ȸ\n";
	return 0;
}
