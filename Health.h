#pragma once
#include <iostream>
#include <string>

class Health
{
public:
	Health();
	Health(char _gender, double _cm, double _kg);
	Health(const Health& other);
	~Health();
public:
	inline char getGender() const { return gender; }
	inline double getCm() const { return cm; }
	inline double getKg() const { return kg; }
	std::string showObsityResult();
public:
	void setGender(char _gender) { gender = _gender; }
	void setCm(double _cm) { cm = _cm; }
	void setKg(double _kg) { kg = _kg; }

protected:
	char gender;
	double cm;
	double kg;
private:
};