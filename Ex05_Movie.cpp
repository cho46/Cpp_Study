#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#define RATING_MAX_COUNT 100

class Movie
{
public:
	Movie(string _title, string _director)
	{
		title = _title;
		director = _director;
	}
	void addRating(int num)
	{
		if (num >= 1 &&num<=5)
		{
			rating[ratingCount++] = num;
		}
		else
			cout << "잘못된 평점으로 스킵합니다." << endl;
	}
	double calcRating()
	{
		for (int i = 0; i < ratingCount; i++)
		{
			total += rating[i];
		}
		total /= ratingCount;
		return total;
	}
	void printList();

	void print()//영화제목: _ , 감독: _ , 평균 평점: _
	{
		cout << "영화제목: " << title << " 감독: " << director<< " 평균평점" << calcRating() << endl;

		cout << "평점 리스트 : " << printList();
	}
	


private:
	string title;
	string director;
	int rating[RATING_MAX_COUNT] = { 0 };//평점은 최대 100건까지
	int ratingCount = 0;		//현재 저장된 평점 개수
	double total = 0.0;
};



int main()
{
					//영화제목, 감독
	Movie m1("인셉션", "크리스토퍼 놀란");
	Movie m2("기생충", "봉준호");

	//평점 추가(1점부터 5점)
	m1.addRating(5);
	m1.addRating(3);
	m1.addRating(4);
	m1.addRating(4);
	m1.addRating(-3);

	m2.addRating(4);
	m2.addRating(3);
	m2.addRating(4);
	m2.addRating(4);
	m2.addRating(5);
	m2.addRating(9999);
	m2.addRating(0);
	m2.addRating(4);
	m2.addRating(4);
	m2.addRating(4);


	cout << "\n * 영화정보 * \n";
	m1.print(); 
	m2.print();




	return 0;
}

void Movie::printList()
{
	for (int i = 0; i < ratingCount; i++)
	{
		if (rating[i] >= 1 && rating[i] <= 5)
			cout << rating[i] << " ";
	}
	cout << endl;
}
