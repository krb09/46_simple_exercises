// fastest_3_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int a[] = { -15,-10,-9,-6,-5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int l = 0;
	int h = 19;
	int len = 19;
	while (l < h)
	{
		if (-a[l] - a[h] >= a[19])
			l = l + 1;
		else if (a[h] - (-a[l]) >= -a[0])
			h = h - 1;
		else
		{
			for (int i = 0; i < len; i++)
			{
				if (a[l] + a[h] + a[i] == 0 && i!=l && i!=h)
				{
					cout << "(" << a[i] << "," << a[l] << "," << a[h] << ") sum to zero at positions (" << i << "," << l << "," << h << ")" << endl;
				}
			}
			h = h - 1;
		}
	}
}

