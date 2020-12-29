#include "Header.h"

using namespace std;

int main()
{
	const int SIZE = 10;
	int a;

	srand(time(NULL));
	
	for (int i = 0; i < SIZE; i++)
	{
		a = rand() % 100;
		cout << a << "\n";
	}





	return 0;
}

