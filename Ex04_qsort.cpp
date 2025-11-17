#include <iostream>
#include <cstdlib> //qsort
#include <cstring>
#include <string>
using std::cin;
using std::cout;
using std::endl;


int compareIntAsc(const void* a, const void* b)
{
	//void* -> int*-> 역참조(int)
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	//if (n1 < n2)
	//	return 1;
	//else
	//	return 0;

	return n1 - n2;
}
double compareFloatAsc(const void* c, const void* d)
{
	double d1 = *(double*)c;
	double d2 = *(double*)d;

	if (d1 > d2)
		return 1;
	else if (d1 < d2)
		return -1;
	else
		return 0;
}

int compareStringAsc(const void* a, const void* b)
{
	char str1 = *(char*)a;
	char str2 = *(char*)b;

	//const char* str1 = (const char*)a;
	//const char* str2 = (const char*)b;

	return str1-str2;
}

int main()
{
	//int arr[10] = { 5,7,4,1,9,10,8,2,3,6 };
	//double arr[5] = { 2.2, 3.3, 4.4, 1.1, 5.5 };
	//const char* arr[5] = { "Cherry","Banana","Mango","Apple","Strawberry" };

	char arr[7] = "cadbe";

	printf("정렬 전:");
	for (const auto& at : arr)
		cout << at << " ";
	cout << endl;

	//qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), compareIntAsc); //qsort(배열의 이름, 배열의 크기, 배열 하나값의 크기,정렬을 진행할 함수)
	//qsort(arr, sizeof(arr) / sizeof(double), sizeof(double), compareFloatAsc);
	qsort(arr, sizeof(arr) / sizeof(char)-2, sizeof(char), compareStringAsc);

	printf("정렬 후:");
	for (const auto& at : arr)
		cout << at << " ";
	cout << endl;
	return 0;
}