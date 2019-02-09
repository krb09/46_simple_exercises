// Recursive_Largest_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int largest(int[], int, int);
int main()
{
	int a[] = { 10,6,9,2,10 };
	cout << largest(a, 0, 4)<<endl;
}
int largest(int arr[], int l, int h)
{
	if (l == h)
		return arr[l];
	else
	{
		int mid = (l + h) / 2;
		int k1 = largest(arr, l, mid);
		int k2 = largest(arr, mid + 1, h);
		if (k1 >= k2)
			return k1;
		else
			return k2;
	}
}
