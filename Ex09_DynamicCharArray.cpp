#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class DynamicCharArray
{
public:
	DynamicCharArray(int _size)
	{
		if (_size < 1)
			return; // 생성자에서도 리턴으로 종료가능
		size = _size;
		arr = new char[size];
		std::memset(arr, 0, size);
	}
	
	DynamicCharArray(const char* pStr)
	{
		size = strlen(pStr)+1;
		arr = new char[size];
		std::memset(arr, 0, size);
		strcpy(arr, pStr);

	}
	~DynamicCharArray()
	{
		delete[] arr;
	}
public:
	char getAt(int index)
	{
		if (isVaildRange(index))
			return arr[index];
		else
			return 0;
	}
	void setAt(char input, int index)
	{
		if(isVaildRange(index))
			arr[index] = input;
	}
	void setString(const char *pStr)
	{
		if(strlen(pStr) < size)
			strcpy(arr, pStr);
		else
		{
			delete[] arr;
			size = strlen(pStr)+1;
			arr = new char[size];
			strcpy(arr, pStr);
			
			

		}
	}
	const char* getString()
	{
		return arr;
	}
	int getLength()
	{
		return strlen(arr);
	}
	void trim()
	{
		char *arr2 = new char[size];
		int newIndex = 0;
		std::memset(arr2, 0, size);
		for (int i = 0; i < size; i++)
		{
			if (arr[i] != ' ')
				arr2[newIndex++] = arr[i];
		}
		delete[] arr;
		arr = arr2;
	}
	int getCount(char find)
	{
		int cnt = 0;
		//for (int i = 0; i<size; i++) 배열의 크기만큼
		for (int i = 0; arr[i]!=0; i++) // 저장된 문자열만큼만
		{
			if (find == arr[i])
				++cnt;
		}
		return cnt;
	}
	inline bool isUpper(char ch)
	{
		/*if (ch >= 'A' && ch <= 'Z')
			return true;
		else
			return false;*/
		return (ch >= 'A' && ch <= 'Z');
	}
	inline bool isLower(char ch)
	{
		//if (ch >= 'a' && ch <= 'z')
		//	return true;
		//else
		//	return false;
		return (ch >= 'a' && ch <= 'z');
	}
	void upperString()
	{
		for (int i = 0; arr[i] != 0; i++)
		{
			if (isLower(arr[i]))
				arr[i] -= 32;
		}
	}
	void lowerString()
	{
		for (int i = 0; arr[i] != 0; i++)
		{
			if (arr[i] >= 'A' && arr[i] <= 'Z')
				arr[i] += 32;
		}
	}
private:
	bool isVaildRange(int index)
	{
		if (index >= 0 && index < size)
			return true;
		else
			return false;
	}
private:
	int size = 0;
	char* arr = nullptr;
};


int main()
{
	int count;
	
	cout << "char형 메모리를 몇 개 할당하시겠습니까?";
	cin >> count;
	DynamicCharArray c1(count);
	c1.setAt('R', 1);
	cout << "arr[1] = " << c1.getAt(1) << "입니다.\n";

	DynamicCharArray c2(255);
	c2.setString("Hello World");
	cout << "문자열 출력 = " << c2.getString() << endl;
	c2.trim(); // 공백제거
	cout << "공백 제거 문자열= " << c2.getString() << endl;
	cout << "문자열의 길이 = " << c2.getLength() << endl;


	DynamicCharArray c3("Happy Birthday");
	cout << "문자열 출력 = " << c3.getString() << endl;
	cout << "문자열의 길이 = " << c3.getLength() << endl;


	cout << "p의 개수는 [" << c3.getCount('p') << "]개 입니다.\n";
	c3.upperString();


	return 0;
}