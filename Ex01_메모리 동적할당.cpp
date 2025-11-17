#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int num;
	cout << "학생 수 입력: ";
	cin >> num;

	//int score[num]; // error: 배열의 크기는 상수만 가능(변수는 불가능)
	int *score = new int[num]; //동적할당 => heap영역에 할당


	//동적할당된 메모리는 반드시 제거돼야 한다.(메모리 누수 발생)
	//delete[] score; // 포인터가 가리키는 메모리가 배열인 경우 []를 추가
	
	int total = 0;
	for (int i = 0; i < num; i++)
	{
		cout << "학생 점수 입력: ";
		cin >> score[i];
		total += score[i];
	}
	cout << "학생 점수 평균은" << (double)total / num << "입니다\n";
	delete[] score;

	return 0;
}