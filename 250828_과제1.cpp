#include <iostream>
#include <cstring> //<string.h>
using std::cout;
using std::cin;
using std::endl;
#pragma warning (disable : 4996)

char* addString(char *str1, char *str2);


int main() {
	char str1[10] = "Go";
	char str2[10] = "ahead";

	char* strConnect = addString(str1, str2);

	cout << "연결 된 문자열은 [" << strConnect << "] 입니다.\n";
	delete[] strConnect;
	return 0;
}

char* addString(char *str1, char *str2)
{
	char* temp = new char[255];
	strcpy(temp, str1);
	strcat(temp, str2);

	return temp;
}
