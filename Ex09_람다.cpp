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

	//remove_if : 필터링후, 조건에 맞지 않는 요소의 시작 주소를 가리키는 Iterator를 리턴
	//remove_if는 필터링된 요소를 앞에서 부터 채움.(순서유지)

	nums.erase(std::remove_if(nums.begin(), nums.end(), [limit](int num) {return num > limit; }),nums.end());



	return 0;
}