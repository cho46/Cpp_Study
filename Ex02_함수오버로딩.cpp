#include <iostream>
using namespace std;


//함수 오버로딩
int add(int n1, int n2);
double add(double n1, double n2);
int add(int *arr,int size);
double add(double* arr, int size);

int main()
{
	cout << add(3, 5) << endl;
	cout << add(1.1, 3.4) << endl;

	int arr[5] = { 1,2,3,4,5 };
	int size = 5;
	cout << add(arr,size) << endl;

	double nums[3] = {1.1, 2.2, 3.3};
	cout << add(nums, 5) << endl;

	return 0;
}

int add(int n1, int n2)
{
	cout << "1번호출";
	return n1 + n2;
}

double add(double n1, double n2)
{
	cout << "2번호출";
	return n1 + n2;
}

int add(int *arr,int size)
{
	int total=0;
	for (int i = 0; i <= size; i++)ｓ
	{
		total += arr[i];
	}
	return total;
}

double add(double* arr, int size)
{
	double total = 0;
	for (int i = 0; i < size; i++)
	{
		total += arr[i];
	}
	return total;
}
