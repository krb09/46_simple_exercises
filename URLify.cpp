

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a = "Mr John Smith      ";
	int count = 13;
	int number_spaces = 0;
	int last_space = 0;
	for (int i = 0; i < count; i++)
	{
		if (a[i] == ' ')
			number_spaces = number_spaces + 1;
	}

	int shift = (number_spaces * 3) - number_spaces;		//const

	for (int i = count-1; i >= 0; i--)
	{
		if (a[i] == ' ')
		{
			a[i + shift] = '%';
			a[i + shift-1] = '0';
			a[i + shift-2] = '2';
			shift = shift - 2;
		}
		else
		{
			a[i + shift] = a[i];
		}
	}

	cout << a << endl;
}

