// SortAnagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;
void sort_add(string, multimap<string, string, less<string>> *);
int main()
{
	string s[] = { "cat","hat","fire","rife","acme","mean","name","bat","tab"};
	multimap<string, string, less<string>> table;
	for (int i = 0; i < 9; i++)
	{
		sort_add(s[i], &table);
	}
	for (auto mapItem : table) {
		static int add = 0;
		cout << mapItem.first << '\t' << mapItem.second << '\n';
		s[add++] = mapItem.second;
	}
	for (int i = 0; i < 9; i++)
	{
		cout<<(s[i])<<" ";
	}
}
void sort_add(string a, multimap<string, string, less<string>> *temp)
{
	string s = a;
	char temp_1;
	for (int i = 0; i < a.length()-1; i++)
	{
		for (int j = 0; j < a.length()-1-i; j++)
		{
			if (a[j] > a[j+1])
			{
				temp_1 = a[j];
				a[j] = a[j+1];
				a[j+1] = temp_1;
			}
		}
	}
	(*temp).insert(make_pair(a, s));
}
