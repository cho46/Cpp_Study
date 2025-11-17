#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

template <typename type>
void display(const vector<type>&container)
{
	for (const auto& at : container)
		cout << at << " ";
	cout << endl;
}


int main()
{
	//벡터를 7개 생성 후, 1~7까지 초기화
	//vector<int> v1/* = */{1,2,3,4,5,6,7};
	vector<int> v1{ 1,2,3,4,5,6,7 };
	//v1.size = 백터의 크기
	//v1.cpapcity = 백터의 사이즈
	cout << "v1 size= " << v1.size() << ", " << v1.capacity() << endl;

	/*display(v1);
	v1.reserve(10);
	display(v1);
	v1.insert(v1.begin(), 10);
	display(v1);
	v1.erase(v1.begin(),v1.end());*/


	//vector<char> v2{ 'a','b','c' };
	//cout << "v2 size= " << v2.size() << ", " <<"v2 capacity= " << v2.capacity() << endl;
	//display(v2);


	////vector<int> v3(20); //백터의 크기를 넘김
	////vector<int> v3{ 20 }; //백터를 1개 생성 후, 20으로 초기화
	////vector<int> v3(10, 7);// 백터를 10개 생성 후에 7로 초기화
	//vector<int> v3{ 10,2,3,4,5,7};
	////v3.insert();
	//display(v3);
	//cout << "v3 size= " << v3.size() << ", " << "v3 capacity= " << v3.capacity() << endl;
	//cout <<"앞통수 = " << v3.front() << " , " <<"뒷통수 = " << v3.back() << endl;

	//try {
	//	cout << "두 번째 요소: " << v3[1] << endl;
	//	cout << "두 번째 요소: " << v3.at(1) << endl;
	//}
	//catch (std::exception& exp)
	//{
	//	cout << exp.what() << endl;
	//}

	//vector<std::string> v4{ "apple","banana","orange","strawberry"};
	//cout<<"사이즈" << v4.size(); //4
	//cout <<"캐패"<< v4.capacity(); //4
	//v4.insert(v4.begin()+2, 5,"cherry"); // insert(위치, 값) //현재 기준, orange앞에 cherry가 들어감
	//cout << "사이즈" << v4.size(); //5
	//cout << "캐패" << v4.capacity(); //6
	////cout << *(v4.end() - 1) << endl; //이렇게 해야 strawberry가 나옴
	//display(v4);

	////iterator(반복자)
	//for (auto p = v4.begin(); p != v4.end(); p++)
	//	cout << *p << " ";
	//cout << endl;
	//
	vector<int> v5 = { 1,2,3,4,5,6,7,8,9 };
	//v5.push_back(10);
	//v5.push_back(20);
	//v5.push_back(30); //뒤에 요소 삽입
	//v5.pop_back(); //맨뒤 요소 삭제
	//v5.resize(100); //size를 재조정 - 모든 메모리 0으로 채워짐
	v5.resize(11); //size를 재조정 - 모든 메모리 0으로 채워짐
	//v5.reserve(1000);
	display(v5);
	////capacity는 사이즈가 기존보다 클때만 늘어나서 다시 줄지는 않음
	//cout << "v3 size= " << v5.size() << ", " << "v3 capacity= " << v5.capacity() << endl;
	
	return 0;
}