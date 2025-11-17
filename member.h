#pragma once
#include "Health.h"

class member : public Health
{
public:
	member();
	member(char _gender, double cm, double kg);
	std::string showObsityResult();
	~member();
public:
	double getStandard();
	double getCondition();
	std::string getIsFactor();
protected:
private:
	double standard; //표준체중
	double condition; // 비만도
	std::string isFactor; //체크결과
};