#include <iostream>
#include <string>
#include <unordered_map> 
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

int main()
{
	unordered_map<string, int> score;

	score["Kim"] = 90;
	score["Lee"] = 100;
	score["Jung"] = 0;
	score["Kang"] = 22;
	score["Lim"] = 55;

	cout << "kim 점수 = " << score["Kim"] << endl;

	score["Kim"] = 0; //수정

	//정렬 불가능 => Iterator가 random Access를 할수 없기 때문에,,
	// Vector, List 같은 곳으로 이동 후, 정렬
	//std::sort(score.begin(), score.end());




	cout << "-- 저장 요소 출력 --\n";
	for (auto el : score)
		cout << el.first << " = " << el.second << endl;

	//insert 삽입시 중복되는 경우 무시 => 삽입 성공시 1을 리턴, 실패시 0을 리턴
	auto result = score.insert({ "Park", 38 });
	if (result.second == 0)
		cout << "이미 존재하는 값 입니다.\n";
	else
		cout << "삽입 성공\n";

	//find를 이용한 탐색
	//탐색된 Iterator를 리턴, 탐색된 결과가 없는 경우? end()를 리턴
	auto it = score.find("Lee");
	if (it != score.end())
		cout << "검색된 결과는 " << it->first << " : " << it->second << endl;
	else
		cout << "존재하지 않습니다.\n";

	//count를 이용한 탐색, 존재하면 1, 아닐경우 0 리턴
	cout << "Park은 존재하나요?" << score.count("Park") << endl;



	cout << "size = " << score.size() << endl;
	cout << "bucket count = " << score.bucket_count()<<endl;

	//삭제
	score.erase("Kim");
	cout << "Kim은 존재하나요?" << score.count("Kim") << endl;


	for(int i = 0;i<score.bucket_count();i++)
		cout << "bucket" << i << "size = " << score.bucket_size(i) << endl;

	//전체삭제
	score.clear();

	//해시테이블에 저장된 개수
	cout << "size = " << score.size() << endl;
	//해시테이블의 크기(버킷의 개수)
	cout << "bucket count = " << score.bucket_count() << endl;
	//bucket에 들어있는 요소의 수(슬롯)의 수
	for (int i = 0; i < score.bucket_count(); i++)
		cout << "bucket" << i << "size = " << score.bucket_size(i) << endl;

	//rehash: 버킷의 개수가 n개 이상 되도록 rehashing(2의 거듭제곱)
	score.rehash(20);
	cout << "rehash size = " << score.bucket_count() << endl;
	return 0;
}