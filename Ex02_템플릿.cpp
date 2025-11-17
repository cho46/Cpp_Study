#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using std::cin;
using std::cout;
using std::endl;

template <typename T, int count>
void display(T value)
{
	int i;
	for (i = 0; i < count; i++)
	{
		cout << value << " ";
	}
	cout << endl;
}

template <typename Type>
void print(Type arg)//한개 받는애
{
	cout << arg << endl;
}


template <typename Type, typename... Types>
void print(Type arg, Types... args)//여러개 받는애
{
	cout << arg << " ";
	print(args...);
}



int main()
{
	print("Hello World");
	print(5, 6);
	print(1, 2, 3, 4, 5, 6, 7, 8);


	//템플릿으로 자료형이 아닌 값 전달도 가능
	display<int,3>(5);
	display<double, 10>(3.14);
	display<char, 2>('Q');

	return 0;
}