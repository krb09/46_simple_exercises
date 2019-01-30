// StringPermutaiton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a = "dog";
	string b = "god";
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < a.length(); i++)
	{
		count1 = count1 + a[i];
	}
	cout << count1 << endl;
	for (int j = 0; j < b.length(); j++)
	{
		count2 = count2 + b[j];
	}
	cout << count2 << endl;
	if (count1 == count2)
		cout << "Its a permutation";
	else
		cout << "Its not a permutation";
}

