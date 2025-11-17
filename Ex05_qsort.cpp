#include <iostream>
#include <cstdlib> //qsort
#include <cstring>
#include <string>
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

struct student
{
	std::string name;
	int score;
};

std::ostream& operator<<(std::ostream& out,const student& st)
{
	cout << "[" << st.name << ", " << st.score << "] \n";
	return out;
}

int compareIntAsc(const void* a, const void* b)
{
	int n1 = ((student*)a)->score;
	int n2 = ((student*)b)->score;

	return n1 - n2;
}
int compareStrAsc(const void* a, const void* b)
{
	student* s1 = (student*)a;
	student* s2 = (student*)b;

	return strcmp(s1->name.c_str(), s2->name.c_str());
}

int main()
{
	student arr[5] = {
	{"홍길동",55},
	{"이길동",33},
	{"고길동",22},
	{"나길동",100},
	{"차길동",66}
	};

	printf("정렬 전:");
	for (const auto& at : arr)
		cout << at << " ";
	cout << endl;

	//22,33,55,66,100 - 점수기준
	//qsort(arr, sizeof(arr) / sizeof(student), sizeof(student), compareIntAsc);
	qsort(arr, sizeof(arr) / sizeof(student), sizeof(student), compareStrAsc);


	printf("정렬 후:");
	for (const auto& at : arr)
		cout << at << " ";
	cout << endl;
	return 0;
}