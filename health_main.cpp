#include <iostream>
#include "member.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	member m1('F', 163.78, 52.74);
	member m2('M', 178, 59);
	member m3('M', 182, 108.3);

	cout<<m1.showObsityResult();
	cout << m2.showObsityResult();
	cout << m3.showObsityResult();

	return 0;
}
/*
	showObsityResult() 함수의 출력 결과는 다음과 같다.

	*****비만도 Check*****
	성별(M / F) : F
	신장(Cm) : 163.78
	체중(Kg) : 52.74

	=> 표준체중 : 54.213
	=> 당신은 비만도는 (97.283)% 로 (표준체중) 입니다.
*/