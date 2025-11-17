#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool isOdd(int value)
{
	if (value % 2 == 1)
		return true;
	else
		return false;
}

bool isEven(int value)
{
	if (!(value % 2))//if(value % 2==0)
		return true;
	else
		return false;
}
bool isThree(int value)
{
	if (value % 3 == 0)
		return true;
	else
		return false;
}
void showif(int* arr, int size, bool(*pred)(int))
{
	for (int i = 0; i < size; i++)
	{
		if(pred(arr[i]))
			cout<<arr[i]<<" ";
	}
	cout << endl;
}

int main()
{
	int nums[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("홀수 출력: ");
	showif(nums, 10, isOdd);
	printf("짝수 출력: ");
	showif(nums, 10, isEven);

	printf("3의 배수: ");
	showif(nums, 10, isThree);
	return 0;
}