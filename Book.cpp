#include "Book.h"
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)



bool Book::borrowBook()
{
	if (!isBorrowed)//대여중이 아니라면
	{
		isBorrowed = true; // 대여
		return true; // 성공
	}
	return false;//실패
};
//반납함수: 대여중이라면 반납(false)
bool Book::returnBook()
{
	if (isBorrowed) //대여중이라면
	{
		isBorrowed = false; // 반납
		return true;//성공
	}
	return false;//실패
}

void Book::displayBookInfo()
{
	std::cout << "[도서명: " << title
		<< " 작가: " << author
		<< " 가격: " << price
		<< " 대여상태: " << (isBorrowed ? "대여중" : "도서보유중")<<"]\n";
}

Book::Book()
{
	//책 제목: Unknown, 작가: Unknown, 가격: 0으로 초기화
	title = new char[8];
	std::strcpy(title, "Unknown");
	
	author = new char[8];
	std::strcpy(author, "Unknown");

	price = 0;
	isBorrowed = false;
}

Book::Book(const char* title, const char* author, int price)
{
	//매개변수의 값으로 초기화
	this->title = new char[strlen(title) + 1];
	std::strcpy(this->title,title);

	this->author = new char[strlen(author) + 1];
	std::strcpy(this->author, author);

	this->price = price;
	isBorrowed = false;
}

Book::Book(const Book& other) : Book(other.title, other.author, other.price) {}

Book::~Book()
{
	delete[] this->title;
	delete[] this->author;
}

inline void Book::setTitle(const char* Title)
{
	if (this->title != nullptr)
		delete[] this->title;

	this->title = new char[strlen(Title) + 1];
	strcpy(this->title, Title);
}

inline void Book::setAuthor(const char* author)
{
	if (this->author != nullptr)
		delete[] this->author;

	this->author = new char[strlen(author) + 1];
	strcpy(this->author, author);
}

