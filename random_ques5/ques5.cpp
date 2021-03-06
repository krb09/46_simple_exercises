/*ques 5. Write a function translate()that will translate a text into "rövarspråket" (Swedish for "robber's
language"). That is, double every consonant and place an occurrence of "o"in between. For example,
translate("this is fun")should return the string "tothohisos isos fofunon".*/ 

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
void translate(string, int);
int main()
{
	string s,k1;
	cout << "Enter your phrase: ";
	getline(cin, s, '.');
	int k = s.length();
	translate(s,k);
}
void translate(string a, int n)
{
	char x[] = { 'a','e','i','o','u','A','E','I','O','U'};
	string result;
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < 10 && flag == 0; j++)
		{
			if (a[i] == x[j])
				flag = 1;
			else
				flag = 0;
		}
		if (flag == 1)
			result = result + a[i];
		else
			result = result + a[i] + 'o' + a[i];
	}
	cout << result;
}