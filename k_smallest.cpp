// k_smallest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int k_smallest(int[], int, int,int,int);
int return_pivot(int[], int, int);
int main()
{
	int a[] = { 4,7,3,6,8,1,9,2 };
	int k = 3;
	int len = 8;
	cout << k_smallest(a, 0, 7,k,len) << endl;
}
int k_smallest(int arr[], int l, int h, int k,int len)
{
	int pivot = return_pivot(arr, l, h);
	if (pivot == len - k)
		return arr[pivot];
	else if (pivot > len - k)
		return k_smallest(arr, l, pivot - 1, k, len);
	else if (pivot < len - k)
		return k_smallest(arr, pivot+1, h, k, len);
}
int return_pivot(int arr_1[], int l, int h)
{
	int pivot_val = arr_1[l];
	while (l < h)
	{
		while (arr_1[h] >= pivot_val && l<h)
			h--;
		if (l != h)
		{
			arr_1[l] = arr_1[h];
			l++;
		}
		while (arr_1[l] <= pivot_val && l<h)
			l++;
		if (l != h)
		{
			arr_1[h] = arr_1[l];
			h--;
		}
	}
	arr_1[l] = pivot_val;
	return l;
}