#include <iostream>
#include "Student.h"
using std::cout;
using std::cin;
using std::endl;





int main()
{
	Student s1; //인스턴스 생성

	cout << "s1 " << s1.toString() << endl;

	Student s2("홍길동", 19, "123-5678", "컴퓨터 공학전공");
	cout << "s2 " << s2.toString() << endl;

	Student s3 = s2;
	cout << "s3= " << s3.toString() << endl;

	return 0;
}
