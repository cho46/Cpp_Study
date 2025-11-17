#include <iostream>
#include <cstdlib> //qsort
#include <cstring>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class figure
{
public:
	figure() : height(0), ch('X'){}
	figure(int height, char ch) : height(height), ch(ch){}
	virtual void Draw(){}
	virtual ~figure() {}

protected:
	int height; // 높이
	char ch;    // 출력문자
};

class triangle : public figure
{
public:
	triangle(int height, char ch) : figure(height, ch)
	{

	}
	void Draw() override
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j <= i; j++)
				cout << ch;
			cout << endl;
		}
	}
};
class pyramid : public figure
{
public:
	pyramid(int height, char ch) : figure(height, ch)
	{

	}
	void Draw() override
	{
		for (int i = 0; i < height; i++)
		{
			for (int k = height-i; k > 0; k--)
			{
				cout << " ";
			}
			for (int j = 0; j <= i; j++)
			{
				cout << ch<<" ";
			}
			
			cout << endl;
		}
	}
};
class quadrangle : public figure
{
public:
	quadrangle(int height, char ch) : figure(height, ch)
	{

	}
	void Draw() override
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << ch;
			}
			cout << endl;
		}
	}
};
class diamond : public figure
{
public:
	diamond(int height, char ch) : figure(height, ch)
	{

	}
	void Draw() override
	{
		if (height % 2 == 0)
		{
			cout << "짝수는 못그립니다.";
			return;
		}

		for (int i = 0; i <= height / 2; i++)
		{
			for (int k = 0; k < height / 2 - i; k++)
			{
				cout << " ";
			}
			for (int j = 0; j <= i; j++)
			{
				cout << ch << " ";
			}
			cout << endl;
		}
		for (int i = height / 2 - 1; i >= 0; i--)
		{
			for (int k = 0; k < height / 2 - i; k++)
			{
				cout << " ";
			}
			for (int j = 0; j <= i; j++)
			{
				cout << ch << " ";
			}
			cout << endl;
		}
	}
};
// 부모의 포인터로 자식 인스턴스의 주소를 저장할 수 있다.
figure* fi = nullptr;

int main()
{
	//부모의 포인터로 자식 인스턴스의 주소를 저장할 수 있다.	
	figure* fi = nullptr;

	while (true)
	{
		system("cls");
		cout << "\n\n\t\t *** 그리기마당 ***\n\n";
		cout << "1. 직각삼각형    2. 피라미드    3. 사각형    4. 다이아몬드    0. Terminate\n";
		cout << "\n메뉴선택 : ";
		int choice;
		cin >> choice;

		if (choice == 0)
			exit(0);

		cout << "높이: ";
		int height;
		cin >> height;

		cout << "출력 문자: ";
		char ch;
		cin >> ch;

		switch (choice)
		{
		case 1:
			fi = new triangle(height, ch);
			break;
		case 2:
			fi = new pyramid(height, ch);
			break;
		case 3:
			fi = new quadrangle(height, ch);
			break;
		case 4:
			fi = new diamond(height, ch);
			break;
		}

		//가상 메서드인 경우 포인터가 가리키는 타입에 따라 호출되는 메서드가 달라진다.
		fi->Draw(); //생성된 인스턴스에 따라 다양한 도형 출력
		delete fi; //부모, 자식 모두 소멸

		cout << "\n\n\t\t";
		system("pause");
	}
	return 0;
}