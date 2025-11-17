#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Book
{
public:
	Book(string name, string writer, int _year = 1900)
	{
		title = name;
		author = writer;
		if(_year>1)
			year = _year;
		isBorrowed = false;
	}
	void print()
	{
		cout << "도서명 : " << title << " 작가: " << author << " 발행년도 : " << year << "대출가능여부 : " << (isBorrowed ? "대출중":"대출불가") << endl;
	}

	void borrow()
	{
		if (isBorrowed == true)
		{
			cout << "대출불가.";
		}
		else
		{
			isBorrowed = true;
			cout << "대출되었습니다.";
		}
	}
	void returnBook()
	{
		if (isBorrowed)
		{
			cout << "반납완료";
			isBorrowed = false;
		}
		else
		{
			cout << "이미 반납된 책입니다.";
		}

	}
private:
	string title;
	string author;
	int year;
	bool isBorrowed; // true면 대출중
};


int main()
{
	Book b1("해리포터", "J.K롤링", 1997);
	Book b2("데미안", "헤르만헤세", 1919);
	
	b1.print();//도서명, 작가, 발행년도, 대출중 또는 대여가능
	b2.print();

	cout << "*대출 정보* \n";

	b1.borrow(); // 대출되었습니다.
	b2.borrow();// 이미 대출된 책입니다.

	b1.print(); // 도서명
	b2.print();

	cout << "* 반납 정보 *\n";
	b1.returnBook(); //반납되었습니다.
	b2.returnBook(); // 이미 반납된 책입니다.



	return 0;
}