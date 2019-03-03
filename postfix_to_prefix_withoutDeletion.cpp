// postfix_to_prefix_new.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "pch.h"
#include <iostream>
#include<string>
using namespace std; 

void postfix_to_prefix(string,string &, int);
void prefix_to_postfix(string, string&, int);
bool in_char(char);
bool in_operand(char);
int main()
{
	string postfix = "ab+c*d-";
	string prefix = "-*+abcd";
	static string result = "";
	static string result2 = "";
	postfix_to_prefix(postfix, result, postfix.length() - 1);
	prefix_to_postfix(prefix, result2, 0);
	cout << result << endl;
	cout << result2 << endl;
}
void postfix_to_prefix(string postfix, string &result, int l)
{
	if (l < 0)
		return;
	char c = postfix[l];
	//postfix[l] = '\0';			//no need to delete process
	if (in_char(c))
	{
		result = c + result;
	}
	else
	{
		postfix_to_prefix(postfix, result,l-1);
		postfix_to_prefix(postfix, result, l-2);
		result = c + result;
	}
}
void prefix_to_postfix(string prefix, string &result2, int l)
{
	static int iter = l;
	if (iter > prefix.length()-1)
		return;
	char c = prefix[iter];
	if (in_char(c))
		result2 = result2 + c;
	else
	{
		prefix_to_postfix(prefix, result2, ++iter);
		prefix_to_postfix(prefix, result2, ++iter);
		result2 = result2 + c;
	}
}
bool in_char(char X)
{
	char a[4] = { 'a','b','c','d' };
	for (int i = 0; i < 4; i++)
	{
		if (a[i] == X)
			return true;
	}
	return false;
}
bool in_operand(char X)
{
	char a[4] = { '+','-','/','*' };
	for (int i = 0; i < 4; i++)
	{
		if (a[i] == X)
			return true;
	}
	return false;
}
