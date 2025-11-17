#include <iostream>
#include <cstdlib> // c에있는 stdilb.h
#include <ctime> // c에 있는 time.h
using std::cout;
using std::cin;
using std::endl;



void randomUpper(char *p,int count);
void displayChar(char *p, int count);
int main()
{

	cout << "몇개의 알파벳을 할당하시겠습니까?";

	int count;
	cin >> count;

	char *alpha = new char[count];

	//randomUpper함수: 대문자를 랜덤하게 할당하는 함수
	randomUpper(alpha, count);

	//displayChar함수: 저장된 문자를 출력하는 함수
	cout << "\n랜덤하게 저장된 대문자 출력\n";
	displayChar(alpha, count);





	delete[] alpha;




	return 0;
}

void randomUpper(char* p, int count)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < count; i++)
	{
		p[i] = rand() % 26 + 65;//65~90
	}


}

void displayChar(char* p, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << p[i] << " ";
	}

}
