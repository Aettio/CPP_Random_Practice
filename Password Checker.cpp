#include "Header.h"

using namespace std;

int main()
{
	int code, code2;
	cout << "Welcome " << endl;
	cout << "Enter your code " << endl;
	cin >> code;
	cout << "Your code is " << code << endl;
	if (code == 171717)
	{
		cout << "Password is already used" << endl;
	}
	else
	{
		cout << "Confirm your password" << endl;
		cin >> code2;
		if (code == code2)
		{
			cout << "Password accepted" << endl;
		}
		else
		{
			cout << "Wrong password 1 and password 2" << endl;
		}
	}
	return 0;
}
