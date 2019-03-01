// Quicksort_3way_partitioning.cpp 

#include "pch.h"
#include <iostream>
using namespace std;
void partition_3way(int[], int, int, int&, int&);			//no value returned as i and j are ref and kind of returned values only
void quicksort(int[], int, int);
void swap(int[], int, int);
int main()
{
	int a[] = { 1,2,9,2,3,0,5,7,4,6,6,6,7,8,9,9 };
	int size = 16;
	quicksort(a, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void quicksort(int a[], int l, int h)
{
	if (l >= h)
		return;
	int i, j;
	partition_3way(a, l, h, i, j);
	quicksort(a, l, i - 1);
	quicksort(a, j + 1, h);
}
void partition_3way(int a[], int l, int h, int &lt, int &gt)
{
	lt = l;
	gt = h;
	int iter = l;
	int pivot = a[l];
	while (iter <= gt)
	{
		if (a[iter] == pivot)
			iter++;
		else if (a[iter] < pivot)
		{
			swap(a, iter, lt);
			iter++;
			lt++;
		}
		else
		{
			swap(a, iter, gt);
			gt--;
		}
	}
}
void swap(int a[], int c, int d)
{
	int temp = a[c];
	a[c] = a[d];
	a[d] = temp;
}