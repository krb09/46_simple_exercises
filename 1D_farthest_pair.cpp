/*Q4: Farthest Pair (1 Dimension): Write a program that, given an array a[] of N double values, find a farthest pair: two values whose difference is no smaller
than the difference of any other pair (in absolute value). The running time of the program should be LINEAR IN THE WORST CASE.*/

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	double x[] = { 1.2,2.7,3.9,-9,11,-21,0,1,5 };
	double min = x[0];
	int pos_max;
	double max = x[0];
	int pos_min;
	for (int i = 0; i < 9; i++)
	{
		if (x[i] >= max)
		{
			max = x[i];
			pos_max = i;
		}
		else if(x[i] <= min)
		{
			min = x[i];
			pos_min = i;
		}
	}
	cout << "The elements farthest apart are: " << min<<" at "<<pos_min << " and " << max<<" at "<<pos_max;
}
