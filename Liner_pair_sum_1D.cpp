// HW1_pair_sum.cpp

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int a[] = { -15,-10,-9,-6,-5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int l = 0;
	int h = 18;
	while (l < h)
	{
		if (a[l] + a[h]==0)
		{
			cout << "There is a pair at (" << l << "," << h << ")" << endl;
			l = l + 1;
			h = h - 1;
		}
		else if (a[h] < -a[l])
			l = l + 1;
		else
			h = h - 1;
	}
}
