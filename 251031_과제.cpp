//나만의 예외클래스 만들기

//std::exception과 유사한 기능을 하는 기본 예외 클래스(myException)를 
//직접 만들어보고, 이를 상속받는 여러 자식 예외 클래스를 작성해보기.

//try - catch 구문을 이용해서 예외를 던지고(throw) 받는다(catch)
//다형성(Polymorphsim)이 구현되도록 모든 예외는 myException으로 받는다.


//1. myException 클래스 작성
 //- what()이라는 가상함수를 만든다.
 //- what()함수는 "기본 예외가 발생했습니다!" 라는 문자열을 리턴한다.

//2. myFileException 클래스는 myException를 상속 받는다.
 //- what()함수를 오버라이딩 한다.
 //- what()함수는 "파일 예외가 발생했습니다!" 라는 문자열을 리턴한다.

//3. myNetworkException 클래스는 myException를 상속 받는다.
 //- what()함수를 오버라이딩 한다.
 //- what()함수는 "네트워크 예외가 발생했습니다!" 라는 문자열을 리턴한다.

#include <iostream>

using std::cout;
using std::endl;



class myException
{
public:
	virtual const char* what() const
	{
		return "기본 예외가 발생했습니다!";
	}
};

class myFileException : public myException
{
public:
	const char* what() const override
	{
		return "파일 예외가 발생했습니다!";
	}
};

class myNetworkException : public myException
{
public:
	const char* what() const override
	{
		return "네트워크 예외가 발생했습니다!";
	}
};



int main()
{
	try 
	{
		throw myFileException();
	}
catch (const myException& e) {
	std::cout << e.what() << std::endl;
}

	return 0;
}

