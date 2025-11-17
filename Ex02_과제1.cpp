#include <iostream>
#include <string>
#include <cmath>
#pragma warning (disable:4996)
using std::cout;
using std::cin;
using std::endl;
using std::string;



class MyString
{
public:
	MyString(const char *pStr)
	{
		size = strlen(pStr);
		arr = new char[size+1];
		strcpy(arr, pStr);
	}
	~MyString()
	{
		delete[] arr;
	}
	inline char* getString()
	{
		return arr;
	}
	void replace(char target, char chg)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == target)
 				arr[i] = chg;
		}
	}
    void reverse()
    {
       char* pStr = new char[size+1];
       for (int i = 0; i < size; i++) 
       {
           pStr[i] = arr[size - 1 - i];
       }
	   pStr[size] = 0;
       delete[] arr;
       arr = pStr;
    }
	void clear()
	{
		char* pStr = new char[1];
		pStr[0] = 0;
		delete[] arr;
		arr = pStr;
		size = 0;
	}
	bool sameString(const MyString &other)
	{
		if (strcmp(arr, other.arr) == 0)
			return true;
		else
			return false;
	}
	void* find(char target)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == target)
				return &arr[i];
		}
		return nullptr;
	}
	void insert(int target,const char *input)
	{
		int tarSize = strlen(input);
		int tSize = tarSize + size+1;
		char* pStr = new char[tSize];
		int arrIdx = 0,pStrIdx = 0;
		for (int i = 0; i < tSize - 1; i++)
		{
			if (i == target)
			{
				for (int j = 0; j < tarSize; j++)
				{
					pStr[pStrIdx++] = input[j];
				}
			}
			pStr[pStrIdx++] = arr[arrIdx++];
		}
		pStr[pStrIdx] = '\0';

		delete[] arr;
		arr = pStr;
		size = tSize-1;
	}
	void insert(int target, char input)
	{
		int tSize = size + 2;
		char* pStr = new char[tSize];
		int oldIdx = 0, newIdx = 0;

		for (int i = 0; i < tSize - 1; i++)
		{
			if (i == target)
			{
				pStr[newIdx++] = input; 
			}
			if (oldIdx < size)
			{
				pStr[newIdx++] = arr[oldIdx++];
			}
		}

		pStr[newIdx] = '\0';
		delete[] arr;
		arr = pStr;
		size = tSize-1;
	}
	
private:
	int size = 0;
	char* arr = nullptr;
};

int main()
{
	MyString s1 = "Hello World"; //생성자 호출
	MyString s2 = "My Car"; // 생성자 호출
	
	cout << "s1 = " << s1.getString() << endl;
	cout << "s2 = " << s2.getString() << endl;

	//replace메서드: 특정 문자를 다른 문자로 모두 바꾼다.(ㅣ=>@)
	s1.replace('l', '@');  //=>He@@o Wor@d
	cout << "s1 = " << s1.getString() << endl;

	//reverse메서드: 문자열 역순 저장
	s2.reverse();
	cout << "s2 = " << s2.getString() << endl; // =>rac yM

	// clear메서드: 메모리의 크기를 1로 설정 후, 널문자 저장('\0')
	s1.clear(); 
	cout << "s1 = " << s1.getString() << endl; 

	MyString s3 = "apple";
	MyString s4 = "apple";

	if (s3.sameString(s4))
		cout << "두 문자열은 같습니다.\n";
	else
		cout << "두 문자열은 다릅니다.\n";

	//find 메서드: 검색한 문자의 주소를 리턴함
	//문자가 여러개라면? 첫번째 발견했을때의 주소를 리턴시킴
	cout << "검색 문자는 ["<<s3.find('p') << "]번지에 저장되어 있습니다.\n";

	//insert메서드: 특정 인덱스에 문자열을 추가
	cout << "s3 = " << s3.getString() << endl;
	s3.insert(2,"문자추가");
	cout << "s3 = " << s3.getString() << endl; //ap문자추가ple
	s4.insert(4, 'Z');
	cout << "s4 = " << s4.getString() << endl; //applZe
	return 0;
}