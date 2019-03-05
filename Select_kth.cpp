// Select_kth_smallest.cpp 

#include "pch.h"
#include <iostream>
int select_kth_smallest(int[], int,int, int);
int partition(int[], int, int);
using namespace std;
int main()
{
	int a[] = { 5,8,9,1,7,0,3,4,6,2 };
	int k_index = 9;
	int size = 10;
	int result_k = select_kth_smallest(a, k_index,0, size-1);
	cout << result_k << endl;
	return 0;
}
int select_kth_smallest(int a[], int k,int l, int h)
{
	int j = partition(a, l, h);
	if (j == k)
		return a[j];
	else
	{
		if (j < k)
		{
			l = j + 1;
			select_kth_smallest(a, k,l, h);
		}
		else
		{
			h = j - 1;
			select_kth_smallest(a, k, l, h);
		}
	}
}
int partition(int a[], int l, int r)
{
	int leftindex = l;
	int rightindex = r;
	int pivot = a[l];
	while (l < r)
	{
		while (l<r && a[r]>pivot)
		{
			r--;
		}
		if (l != r)										// when you find smallest on the right side
		{
			a[l] = a[r];
			l++;

		}
		while (l < r && a[l] < pivot)
		{												//until you get smaller values, its okay
			l++;
		}
		if (l != r)										// when you see a value bigger than pivot
		{
			a[r] = a[l];
			r--;

		}
	}
	a[l] = pivot;
	return l;
}