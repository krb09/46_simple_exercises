// AnBn_language.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
bool anbn_language(string, int, int);
int main()
{
	string s = "";
	int begin = 0;
	int len = s.length() - 1;
	if (s.length() == 0)
		cout << "Not from the language anbn." << endl;
	else
	{
		if (anbn_language(s, begin, len))
			cout << "It's from a language anbn." << endl;
		else
			cout << "Not from the language anbn." << endl;
	}
}
bool anbn_language(string str, int l, int r)
{
	static char a = str[l];
	static char b = str[r];
	if (l > r)
		return true;
	else if (str[l++] == a && str[r--] == b)
		return anbn_language(str, l, r);
	else
		return false;
}
