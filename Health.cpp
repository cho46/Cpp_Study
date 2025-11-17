#include "Health.h"

Health::Health() : gender('M'), cm(178.0), kg(64.0)
{
}

Health::Health(char _gender, double _cm, double _kg)
{
	gender = _gender;
	cm = _cm;
	kg = _kg;
}

Health::Health(const Health& other)
{
	gender = other.gender;
	cm = other.cm;
	kg = other.kg;
}

Health::~Health()
{
}

std::string Health::showObsityResult()
{
	std::string s0= "*****비만도 Check*****\n";
	std::string s1 = "성별(M / F) : " + std::to_string(gender)+"\n";
	std::string s2 = "신장(Cm) : " + std::to_string(cm) + "\n";
	std::string s3 = "체중(Kg) : " + std::to_string(kg) + "\n";
	return s0 + s1 + s2 + s3;
}


