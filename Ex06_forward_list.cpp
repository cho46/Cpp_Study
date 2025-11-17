#include <iostream>
#include <forward_list>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::forward_list;


struct citizen
{
	string name;
	int age;
};




bool isEven(int value)
{
	if (value % 2 == 0)
		return true;
	else
		return false;
}

bool isChild(citizen citi)
{
	if (citi.age < 18)
		return true;
	else
		return false;
}

bool isAdult(citizen citi)
{
	if (citi.age != 17)
		return true;
	else
		return false;
}

std::ostream& operator<<(std::ostream& out, const citizen& citi)
{
	cout << "[" << citi.name << ", " << citi.age << "]  ";
	return out;
}


template <typename type>
void display(forward_list<type> list)
{
	for (auto el : list)
	{
		cout << el << " "; //operator<<(cout, el);
	}
	cout << endl;
}

int main()
{//연결리스트 기반 STL
	//forward_list<int> f1 = { 1,2,3,4,5,6,7 };

	//f1.push_front(99); //맨 앞에 값을 추가

	//auto it = f1.begin(); //forward_list<int>::iterator*
	//f1.insert_after(it, 77); //해당 위치 다음에 노드 추가
	//f1.pop_front();//맨 앞 노드를 제거
	//f1.erase_after(f1.begin()); //해당위치 다음에 노드 제거
	////f1.erase_after(f1.begin(), f1.end()); //해당 위치 다음에 노드 제거
	//f1.erase_after(f1.before_begin(), f1.end()); // 맨 앞 노드 앞의 위치 부터 모든 요소 제거
	//f1.clear(); //모든 노드 제거(리스트 초기화)
	//display(f1);

	//cout << *it << endl;
	//display(f1);


	//forward_list<int>f2 = { 2,3,4,5,6,7,8,9,10 };
	//cout << "짝수 데이터 출력\n";
	////홀수 노드는 제거
	//auto prev = f2.before_begin();
	//for (auto it = f2.begin(); it != f2.end(); it++)
	//{
	//	if (*it%2!=0)
	//	{
	//		//erase_after : 노드를 제거한 후, 제거된 위치의 다음 주소를 리턴
	//		it = f2.erase_after(prev);
	//	}
	//	else
	//	{
	//		prev = it;
	//		it++;
	//	}
	//}

	//display(f2);

	//---------------------------------------------------------------------------------------------------------
	//forward_list<string> f3 = { "장보고","이순신","유관순","안중근","윤동주" };

	//auto iter = f3.begin();
	//cout << *iter << endl;

	//std::advance(iter, 3); //iter의 위치를 변경
	//cout << *iter << endl;

	//iter = std::next(iter, 1); //변경된 iterator의 위치를 리턴(iterator의 값은 변경X)
	//cout << *iter << endl;

	//---------------------------------------------------------------------------------------------------------
	//forward_list<int> f4 = { 55,2,97,66,7,80,15,80,85,52,6,80 };


	//f4.sort();
	//cout << "오름차순 정렬 출력 : ";
	//display(f4);

	//f4.sort(std::greater<int>()); //표준으로 제공되는 비교함수 객체, greater를 사용하여 반대로 정렬하여 출력
	//cout << "내림차순 정렬 출력 : ";
	//display(f4);


	//f4.unique();
	//cout << "중복제거후 출력 : ";
	//display(f4);

	////remove_if = 함수에서 true를 리턴한 노드만 제거
	//f4.remove_if(isEven);
	//cout << "홀수 노드만 출력 : ";
	//display(f4);



	//f4.reverse();
	//cout << "역순 저장 출력 : ";
	//display(f4);

	//---------------------------------------------------------------------------------------------------------
	forward_list<citizen> citi = {
		{"장보고",18},{"이순신",17},{"유관순",17},{"안중근",47},{"윤동주",14} };
	cout << "전체 시민 리스트 : ";
	display(citi);

	cout << "투표권이 있는 시민리스트: ";
	auto copy = citi;
	copy.remove_if(isChild);
	display(copy);

	cout << "내년에 투표권을 가질  시민리스트: ";
	auto copy2 = citi;
	copy.remove_if(isAdult);
	display(copy);

	return 0;
}