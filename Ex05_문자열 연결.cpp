#include <iostream>
#include <cstring> //<string.h>
using std::cout;
using std::cin;
using std::endl;

#pragma warning (disable : 4996)

#define BUF_SIZE 1024

int main()
{
	char buf[BUF_SIZE];
	//char* connectStr = nullptr; //연결된 문자열의 주소를 저장하는 포인터
	char* connectStr = new char[1];
	connectStr[0] = '\0';

	char* longestStr = nullptr; //가장 긴 문자열의 주소를 저장하는 포인터
	int longestLen = 0; //가장 긴 문자열의 개수

	int firstLen = 0, secondLen = -1;
	char* firstStr = nullptr, * secondStr = nullptr;

	while (true)
	{
		cout << "문자열 입력(종료 시 exit): ";
		cin.getline(buf, BUF_SIZE);

		//if (buf == "exit") //주소가 같냐?
		//strcmp(주소1, 주소2) : 주소부터 널문자 이전의 모든 문자가 같으면 0을 리턴
		if (strcmp(buf, "exit") == 0)
			break;

		char* temp = new char[strlen(buf) + 1];
		strcpy(temp, buf); //입력 문자열을 임시 저장

		char* newM = new char[strlen(connectStr) + strlen(temp) + 1];
		strcpy(newM, connectStr); //기존 문자열을 복사
		strcat(newM, temp); //입력 문자열을 연결

		delete[] connectStr;
		delete[] temp;

		connectStr = newM;

		if (strlen(buf) > longestLen) //입력 문자열의 길이 > 가장 긴 문자열의 길이
		{
			if (longestStr != nullptr) //기존에 저장된 긴 문자열이 있다면?
				delete[] longestStr; //제거

			longestLen = strlen(buf); //가장 긴 문자열의 길이를 갱신
			longestStr = new char[longestLen + 1]; //가장 긴 문자열을 저장
			strcpy(longestStr, buf);
		}


		if (strlen(buf) > firstLen)
		{
			secondLen = firstLen;
			firstLen = strlen(buf);

			if (secondStr != nullptr)
				delete[] secondStr;
			secondStr = firstStr;
			firstStr = new char[strlen(buf) + 1];
			strcpy(firstStr, buf);
		}
		else if (strlen(buf) > secondLen)
		{
			secondLen = strlen(buf);
			if (secondStr != nullptr)
				delete[] secondStr;

			secondStr = new char[strlen(buf) + 1];
			strcpy(secondStr, buf);
		}
	}

	cout << "연결된 문자열은 " << connectStr << "입니다.\n";
	cout << "가장 긴 문자열은 " << longestStr << "이며, 길이는 " << longestLen << "입니다.\n";
	cout << "두번째로 긴 문자열은 " << secondStr << "이며, 길이는 " << secondLen << "입니다.\n";


	delete[] connectStr;
	delete[] longestStr;
	delete[] firstStr;
	delete[] secondStr;



	return 0;
}