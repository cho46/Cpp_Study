//STL: Standard Template Library

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T, int N>
class myArray
{
public:
	myArray() : index(0),
	{
		std::memset(arr,0,sizeof(T) * N);
	}
		myArray(T arg)
	{
		arr[index++] = arg;
	}

	template <typename T, typename... Ts>
	myArray(T arg, Ts... args) : index(0)
	{
		//첫 번째 값은 대입 후,
		index = 0;
		arr[index++] = arg;

		init(args...);//두번째 값 부터는 재귀 호출로 채우기.
	}
	int getSize()
	{
		return N; //배열의 크기리턴
	}
	T at(int idx)
	{
		//안정적인 코드를 위해 유효성을 체크한다.
		if (idx<0 || idx>this->index)
			throw std::out_of_range("범위를 벗어났습니다.");

		return arr[idx]; //저장된 값을 리턴
	}
	T& operator[](int index)
	{
		return arr[idx];
	}
private:
	template <typename T, typename... Ts>
	void init(T arg, Ts...args)
	{

		arr[index++] = arg;
		init(args...);
	}
	void init(T arg)
	{
		arr[index++] = arg;
	}
	void fill(T fill)
	{
		for (int i = 0; i < N; i++)
			arr[i] = fill;
	}
	T front()
	{
		return arr[0];
	}
	T back()
	{
		return arr[index - 1];
	}
	void display()
	{
		for (const auto& at:arr)
			cout << at << " ";
		cout << endl;
	}
protected:
private:
	T arr[N];
	int index;
};

int main()
{
	//fill, display, front, back
	//
	myArray<int, 3> m1 = { 1,2,3 };

	try
	{
		cout << m1.at(100) << endl;
		cout << m1[2] << endl; //m1.operator[](2) //만약 크기보다 큰수를 대입하는 경우 다운, 혹은 예상치 못한 결과 도출
		m1[2] = 99; //m1.operator[](2)
	}
	catch (std::exception& exp)
	{
		cout << exp.what() << endl;
	}

	for (int i = 0; i < m1.getSize(); i++)
		cout << m1.at(i) << " ";
	cout << endl;

	myArray<char, 5> m2 = { 'a','b' ,'c' ,'d' ,'e' };
	for (int i = 0; i < m2.getSize(); i++)
		cout << m2.at(i) << " ";
	cout << endl;
	return 0;
}