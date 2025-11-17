#include <stdio.h>
namespace myStd
{
	class outstream//시험 1번째 문제
	{
	public:
		outstream &operator<<(int n)
		{
			printf("%d", n);
			return *this;
		}
		outstream& operator<<(double n)
		{
			printf("%f", n);
			return *this;
		}
		outstream& operator<<(char n)
		{
			printf("%c", n);
			return *this;
		}
		outstream& operator<<(const char* n)
		{
			printf("%s", n);
			return *this;
		}

		
	};
	const char* endl = "\n";
	outstream out;
}

using namespace myStd;
int main()
{

	//cout << 5; //cout.operator<<(5);
	out << 5 << 3.14<<endl;
	out << "hello";

	return 0;
}