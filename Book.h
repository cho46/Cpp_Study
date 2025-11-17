#pragma once
class Book
{
public:
	//대여중인지를 체크하는 함수: 대여중이면 true, 아니라면 false
	inline bool isBorrowedCheck() const { return isBorrowed; };
	//대여함수: 아직 대여되지 않았다면? true로 변경
	bool borrowBook();
	//반납함수: 대여중이라면 반납(false)
	bool returnBook();
	void displayBookInfo();
public:
	Book();
	Book(const char* title, const char* author, int price);
	//복사생성자, 소멸자, get,set
	Book(const Book& other);
	~Book();

public:
	inline const char* getTitle() const { return title; };
	inline char* getAuthor() const { return author; };
	inline int getPrice() const { return price; };

public:
	inline void setTitle(const char* Title);
	inline void setAuthor(const char* author);
	inline void setPrice() { this->price = price; };

private:
	char* title = nullptr;
	char* author = nullptr;
	int price = 0;
	bool isBorrowed = false; //대여상태
};