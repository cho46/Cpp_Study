#include "BookContainer.h"
#include <iostream>
using std::cout;

void BookContainer::addBook(const char* title, const char* author,int price)
{
	if (index < BOOK_SIZE)
		p[index++] = new Book(title, author, price);
}

void BookContainer::displayAllBookInfo() const
{
	for (int i = 0; i < index; i++)
	{
		p[i]->displayBookInfo();
	}
}

void BookContainer::displayExpensiveBook(int minPrice)
{
	cout << " * " << minPrice << "원 이상인 도서 출력";
	for (int i = 0; i < index; i++)
	{
		if (p[i]->getPrice() >= minPrice)
			p[i]->displayBookInfo();
	}

}

bool BookContainer::borrowBookContain(const char* target)
{
	for (int i = 0; i < index; i++)
	{
		if (std::strcmp(target, p[i]->getTitle()) == 0) //검색한 도서가 존재한다면
		{
			return p[i]->borrowBook();
		}
	}
	return false;
}

BookContainer::~BookContainer()
{
	for (int i = 0; i < index; i++)
	{
		delete p[i];
	}
}