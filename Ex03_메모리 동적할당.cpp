#include <iostream>
#include <cstdlib> // c에있는 stdilb.h
#include <ctime> // c에 있는 time.h
using std::cout;
using std::cin;
using std::endl;


int *reAlloc(int *oldM, int oldSize, int newSize);
char* reAlloc(char* oldM, int oldSize, int newSize);
double* reAlloc(double* oldM, int oldSize, int newSize);

void displayInteger(int *oldM, int size);


int main()
{
	int* oldM = new int[5];
	for (int i = 0; i < 5; i++)
	{
		oldM[i] = i + 1;
	}


	//reAlloc함수: newsize만큼 메모리 재할당후, 재할당된 메모리의 주소를 리턴
	oldM = reAlloc(oldM, 5, 10);

	oldM[5] = 100;
	oldM[6] = 101;

	displayInteger(oldM, 7);



	return 0;
}

int* reAlloc(int* oldM, int oldSize, int newSize)
{
	if (oldSize > newSize)
		return nullptr;

	int* newM = new int[newSize];

	for (int i = 0; i < oldSize; i++)
		newM[i] = oldM[i];

	delete[] oldM;

	return newM;
}

char* reAlloc(char* oldM, int oldSize, int newSize)
{
	if (oldSize > newSize)
		return nullptr;

	char* newM = new char[newSize];

	for (int i = 0; i < oldSize; i++)
		newM[i] = oldM[i];

	delete[] oldM;

	return newM;

}

double* reAlloc(double* oldM, int oldSize, int newSize)
{
	if (oldSize > newSize)
		return nullptr;

	double* newM = new double[newSize];

	for (int i = 0; i < oldSize; i++)
		newM[i] = oldM[i];

	delete[] oldM;

	return newM;

}

void displayInteger(int* oldM, int size)
{
	for (int i = 0; i < size; i++)
		cout << oldM[i] << " ";
	cout << endl;
}
