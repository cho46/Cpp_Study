#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#pragma warning(disable:4996)

class Schedule
{
public:
	Schedule(const int year,const int month, const int day, const char*memo)
	{
		set_year(year);
		set_month(month);
		set_day(day);
		set_memo(memo);
	}
	Schedule(Schedule& other) : Schedule(other.year, other.month, other.day, other.memo) {}
	inline const int get_year() const { return this->year; }
	inline const int get_month() const { return this->month; }
	inline const int get_day() const { return this->day; }
	inline const char* get_memo() const { return this->memo; }

	void set_year(int year){this->year = year;}
	void set_month(int month) { this->month = month; }
	void set_day(int day) { this->day = day; }
	void set_memo(const char* const memo)
	{
		if (this->memo)
			delete[] this->memo;

		this->memo = new char[std::strlen(memo)+1];
		strcpy(this->memo, memo);
	}

private:
	int year = 0,month = 0,day = 0;
	char* memo = nullptr;

};

int main()
{
	Schedule s1(2021, 12, 21, "신발 구입");
	Schedule s2(2021, 12, 24, "강남역 cgv앞에서 수현이 만남");

	cout << s1.get_year() << "년 " << s1.get_month() << "월 " << s1.get_day() << "일의 일정은 "
		<< s1.get_memo() << "입니다.\n";

	cout << s2.get_year() << "년 " << s2.get_month() << "월 " << s2.get_day() << "일의 일정은 "
		<< s2.get_memo() << "입니다.\n";

	Schedule s3 = s2;

	cout << "일정이 복사됐습니다.\n";
	cout << s3.get_year() << "년 " << s3.get_month() << "월 " << s3.get_day() << "일의 일정은 "
		<< s3.get_memo() << "입니다.\n";

	s3.set_memo("cgv 아니고 메가박스 앞에서 6시에 만나기로 변경");
	cout << s3.get_year() << "년 " << s3.get_month() << "월 " << s3.get_day() << "일의 일정은 "
		<< s3.get_memo() << "입니다.\n";

	return 0;
}