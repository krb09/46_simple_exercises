// leetcode3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <vector>;
using namespace std;
int main()
{
	vector<int> count;
	string s = "abcabcbb";
	const int len = s.length();
	int i = 0;
	unordered_map<char, int> charmap;
	for (int i = 0; i < len; i++)
		charmap.insert(make_pair(int(s[i]), i + 1));
	for (auto mapitem : charmap)
		{
		cout << mapitem.first << " " << mapitem.second << endl;
		count.push_back(mapitem.second);
		}
	for (int i = 0; i < count.size(); i++)
	{
		cout << count[i] << " ";
	}
	cout << endl;
	vector<int> result;
	int length = 1;
	for (int i = 0; i < count.size()-1; i++)
	{
		if (count[i + 1] - count[i] == 1)
			length = length + 1;
		else if (count[i + 1] - count[i] ==2 )
		{
			length = length + 1;
			result.push_back(length);
			length = 0;
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	int max = result[0];
	for (int i = 1; i < result.size(); i++)
	{
		if (max < result[i])
			max = result[i];
	}
	cout << "The maximum is: "<<max;	
}
