// powerOfthree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
bool isDivisibleOfThree(int);
int main()
{
	int num;
	cout << "Enter a number: ";
	cin >> num;
	bool k = isDivisibleOfThree(num);
	cout << k;
}
bool isDivisibleOfThree(int a
)
{
	if (a == 3)
		return true;
	else if (a < 3 || a==10 || a==11)
		return false;
	else
		isDivisibleOfThree(a/3);
}
