// LEETCode26.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> nums = { 0,1,2,3,4,5,6 };
	int temp;
	if (nums.size() != 0)
	{
		int flag = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			static int j = i;
			if (nums[i] < nums[i + 1])
			{
				nums[j + 1] = nums[i + 1];
				j = j + 1;
				flag = 1;
			}
			temp = j;
		}
		if (flag == 0)
			temp = 0;
	}
	else
		temp = -1;
	for (int i = 0; i < temp + 1; i++)
	{
		cout << nums[i] << " ";
	}

}

