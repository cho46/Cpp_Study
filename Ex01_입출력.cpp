#include <iostream>
#include <iomanip> // manipulator, 입출력 조작을 위한 헤더파일. setw, fixedm setprecision
using namespace std;

int main()
{
	/*int n1, n2;

	cout << "두수 입력: ";
	cin >> n1 >> n2;

	cout << "입력받은 두수는" << n1 << "," << n2 << "입니다.";
	cout << endl << endl;

	for (int i = 0; i <= 100; i++)
		cout<< setw(10) << i << " ";
	cout << endl;

	char ch;
	cout << "문자입력: ";
	cin >> ch;

	cout << "입력한 문자는" << ch << "이며, 아스키코드는 " << (int)ch << "입니다.";


	if (ch >= 'A' && ch <= 'Z')
		cout << "대문자" << ch << "를 소문자로 변환" << char(ch + 32) << endl;

		
	double d1, d2;
	cout << "실수 2개 입력: ";
	cin >> d1 >> d2;
	cout << "입력한 실수는 " << d1 <<", " << d2 << "이며, 두 실수의 합은" << d1 + d2 << "입니다. "<<"평균은"<<fixed<<setprecision(2)<<(d1+d2)/2.0<<"입니다.";

	

	char str[255];
	cout << "문자열 입력";
	cin >> str; //입력 받을시 엔터값은 무시된다.
	cin.ignore(); //버퍼에 남아있는 한글자를 무시한다.
	//cin.ignore(1024,'\n'); /최대 1024글자까지 무시, 만약 엔터가 나온다면 엔터까지 무시.
	cin.getline(str, 255);

	cout << "입력한 문자열은" << str << "입니다"<<endl;

	cout << endl<<endl;
	*/
	//문자열과 검색문자를 입력받아 검색문자의 개수를 구한다.
	//문자열 입력: Hello World
	//문자검색: 1
	//문자의 개수는 3개입니다.

	char search[255];
	char ans;
	int count = 0;

	cout << "문자열 입력: ";
	cin.getline(search,255);
	cout << "검색할 문자 입력: ";
	cin >> ans;
	
	for (int i = 0; search[i]!='\n'; i++)
	{
		if (ans == search[i])
			++count;
	}
	cout << "문자의 개수는" << count <<"개" << "입니다";


	return 0;
}