// cplusplus_language

#include "pch.h"
#include <iostream>
#include <string>
using namespace std; 
bool language_recog(string, int);
bool inLetters(char);
bool innumber(int);
int main()
{
	string s = "1xyzuvw";
	if (language_recog(s, s.length()))
		cout << "Its an identifier." << endl;
	else
		cout << "Not an identifier." << endl;
}
bool language_recog(string str, int len)
{
	if (len == 0)
	{
		if (inLetters(str[len]))
			return true;
		else
			return false;
	}
	else if (inLetters(str[len]) || innumber(str[len]))
		return language_recog(str, len - 1);
	else
		return false;
}
bool innumber(int n)
{
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 11; i++)
	{
		if (n == a[i])
			return true;
	}
	return false;
}
bool inLetters(char n)
{
	char a[] = { 'a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K','l','L','m','M','n','N','o','O','p','P','q','Q','r','R','s','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z'};
	for (int i = 0; i < 53; i++)
	{
		if (n == a[i])
			return true;
	}
	return false;
}