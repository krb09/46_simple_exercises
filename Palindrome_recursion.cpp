// Palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
bool palindrome(string s, int, int);
int main()
{
	string s = "kartitrak";
	int len = s.length();
	int begin = 0;
	if (palindrome(s, begin, len-1))
		cout << "Its a palindrome." << endl;
	else
		cout << "Not a palindrome"<<endl;
}
bool palindrome(string str, int l, int r)
{
	if (l > r || str.length() == 1 || str.length() == 0)
		return true;
	else if (str[l++] == str[r--])
		return palindrome(str, l, r);
	else
		return false;
}