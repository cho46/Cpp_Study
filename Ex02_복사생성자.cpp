#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#pragma warning (disable : 4996)
class Memo
{
public: //getXXX
	inline const char* const getSender() const { return this->sender; }
	inline const char* const getReceiver() const { return this->receiver; }
	inline const char* const getMessage() const { return this->message; }

public: //setXXX
	void setSender(const char* const sender)
	{
		//기존에 할당된 문자열이 존재한다면?
		if (this->sender) //if(this->sender != nullptr)
			delete[] this->sender; //기존 문자열을 제거

		this->sender = new char[std::strlen(sender) + 1]; //새로운 문자열의 길이만큼 메모리 공간 할당
		std::strcpy(this->sender, sender); //새로운 문자열 복사
	}

	void setReceiver(const char* const receiver)
	{
		if (this->receiver) //if(this->receiver != nullptr)
			delete[] this->receiver;

		this->receiver = new char[std::strlen(receiver) + 1]; //메모리 공간 할당
		std::strcpy(this->receiver, receiver); //문자열 복사
	}

	void setMessage(const char* const message)
	{
		if (this->message) //if(this->message != nullptr)
			delete[] this->message;

		this->message = new char[std::strlen(message) + 1]; //메모리 공간 할당
		std::strcpy(this->message, message); //문자열 복사
	}

public:
	Memo(const char* const sender, const char* const receiver, const char* const message)
	{
		setSender(sender);
		setReceiver(receiver);
		setMessage(message);

		//this->sender = new char[std::strlen(sender) + 1]; //메모리 공간 할당
		//std::strcpy(this->sender, sender); //문자열 복사

		//this->receiver = new char[std::strlen(receiver) + 1]; //메모리 공간 할당
		//std::strcpy(this->receiver, receiver); //문자열 복사

		//this->message = new char[std::strlen(message) + 1]; //메모리 공간 할당
		//std::strcpy(this->message, message); //문자열 복사
		cout << "Constructor: 동적할당 후 문자열 복사\n";
	}

	Memo(const Memo& other) : Memo(other.sender, other.receiver, other.message) //생성자 호출
	{
		//setter이용
		//setSender(other.sender);
		//setReceiver(other.receiver);
		//setMessage(other.message);		

		//직접 코딩
		//this->sender = new char[std::strlen(other.sender) + 1]; //메모리 공간 할당
		//std::strcpy(this->sender, other.sender); //문자열 복사

		//this->receiver = new char[std::strlen(other.receiver) + 1]; //메모리 공간 할당
		//std::strcpy(this->receiver, other.receiver); //문자열 복사

		//this->message = new char[std::strlen(other.message) + 1]; //메모리 공간 할당
		//std::strcpy(this->message, other.message); //문자열 복사
		cout << "Cony Constructor(깊은복사): 동적 메모리까지 모두 복사\n";
	}

	void displayMessageInfo() const
	{
		cout << "[" << this->message << "],[" << this->sender << "],[" << this->receiver << "]\n";
	}

	~Memo()
	{
		delete[] this->sender;
		delete[] this->receiver;
		delete[] this->message;
		cout << "Destructor: 동적으로 할당된 메모리 제거\n";
	}
private:
	char* sender = nullptr;
	char* receiver = nullptr;
	char* message = nullptr;
};

void display(Memo copy) //여기서 복사 생성자가 호출 됩니다.
{
	copy.displayMessageInfo(); //[메시지][송신자:_][수신자:_]
}

int main()
{
	Memo m1("오늘 날씨는 비가 온다네요.", "홍길동", "이순신"); //메모, 송신자, 수신자
	Memo m2("우산 챙기세요", "장보고", "유관순");			 //메모, 송신자, 수신자

	display(m1);
	display(m2);

	m2.setSender("Jayden Kim");
	cout << "m2의 보내는 이가 변경되었습니다. 변경된 이름은 [" << m2.getSender() << "]입니다.\n";
	display(m2);

	return 0;
}