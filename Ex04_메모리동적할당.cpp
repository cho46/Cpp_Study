#pragma warning(disable:4996)

#include <iostream>
#include <cstdlib> // c에있는 stdilb.h
#include <ctime> // c에 있는 time.h
#include <cstring>

#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;


void swap(char* str1, char* str2);


int main()
{
	char buf1[20] = "Hello", buf2[10] = "world";
	strcat(buf1, buf2);
	cout << "변경전 buf1 = " << buf1 << ", buf2 = " << buf2 << endl;



	char str1[10] = "Hello", str2[10] = "odd";

	cout << "변경전 str1 = " << str1 << ", str2 = " << str2 << endl;

	swap(str1, str2);

	cout << "변경후 str1 = " << str1 << ", str2 = " << str2 << endl;


	return 0;
}

void swap(char* str1, char* str2)
{
	//strlen: 주소부터 널문자 이전의 길이를 구한다.
	char* temp = new char[strlen(str1)+1];

	//출발지주소부터 널문자까지 도착지로 복사
	//strcpy(도착지주소 , 출발지주소)
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);

	delete[] temp;
}
