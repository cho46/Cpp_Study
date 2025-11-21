#include <iostream>
#include <string>
#include <functional>
#include <forward_list>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::function;
using std::forward_list;
using std::vector;

struct Survivor
{
	string name;
	int health;
};

int main()
{
	//값을 복사해서 캡쳐
	int x = 10;
	auto printCopy = [x]() {cout << x << endl; };
	x = 999; //값을 복사해서 사용하기 때문에 변하지 않음

	//값을 참조(메모리 공유)해서 값을 캡쳐
	int y = 10;
	auto printRef = [&y]() {cout << y << endl; };
	y = 999;
	//printRef();
	//printCopy();

	forward_list<Survivor> su = { {"장보고",80},{"이순신",0},{"유관순",22},{"안중근",0},{"윤동주",48}};

	//remove_if : 조건이 true인경우 삭제
	su.remove_if([](const Survivor& user) {return user.health <= 0; }); //함수를 호출할 자리에 람다를 호출함

	for (const auto& el : su)
		cout <<"[" << el.name << "]생존자!\n";

	vector<int> nums = { 1,5,10,15,20 };
	int limit = 10;

	//remove_if는 실제 데이터를 삭제하지 않는다
	//조건에 맞는 요소들을 뒤쪽으로 밀어낸다
	//remove_if : 조건에 맞는 시작 Iterator를 리턴

	nums.erase(std::remove_if(nums.begin(), nums.end(), [limit](int num) {return num > limit; }),nums.end());



	return 0;
}