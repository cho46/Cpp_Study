#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int arr[5] = { 1,2,3,4,5 };

	int nums[3]{ 1,2,3 };
	int digit[100]{};
	for (auto& at : digit)
		at = rand() % 100;

	for (const auto& at : digit)
		cout << std::setw(5) << at;
	cout << endl;









	cout << "C스타일의 for문";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;

	cout << "\nC++ 스타일의 범위를 기반한 for문\n";

	for (int at : arr)
	{
		cout << at << " ";
	}
	cout << endl;

	for (auto &at : arr)
	{
		at += 10;
		cout << at << " ";
	}
	cout << endl;

	char str[3] = { 'a','b','c' };
	
	for (char ch : str)
		cout << ch<<" ";



	return 0;
}