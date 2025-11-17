#include "member.h"
#include <iostream>
using std::cout;
using std::endl;
member::member() : Health(), standard(0.0), condition(0.0), isFactor("표준체중")
{
	
}

member::member(char _gender, double _cm, double _kg) : Health(_gender,_cm,_kg),standard(0.0),condition(0.0),isFactor("표준체중")
{
	if (getGender() == 'M')
		standard = (getCm() - 100) * 0.9;
	else
		standard = (getCm() - 100) * 0.85;

	condition = getKg() / standard * 100;

	if (condition < 90)
		isFactor = "저체중";
	else if (condition >= 91 && condition <= 110)
		isFactor = "표준체중";
	else if (condition >= 111 && condition <= 120)
		isFactor = "과체중";
	else if (condition >= 121 && condition <= 130)
		isFactor = "경도비만";
	else if (condition >= 131 && condition <= 150)
		isFactor = "중도비만";
	else
		isFactor = "과체중";
}


std::string member::showObsityResult()
{
	std::string parentStr = Health::showObsityResult();
	std::string s1 = "=> 표준체중 : " + std::to_string(getStandard()) + "\n";
	std::string s2 = "=> 당신의 비만도는 " + std::to_string(getCondition()) + "% 로 " + getIsFactor() + " 입니다.\n";
	return parentStr + s1 + s2;
}

member::~member()
{
}

double member::getStandard()
{
	return standard;
}

double member::getCondition()
{
	return condition;
}

std::string member::getIsFactor()
{
	return isFactor;
}

