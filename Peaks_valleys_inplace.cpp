// Peaks_valleys

#include "pch.h"
#include <iostream>
void peaks_valleys(int[],int);
int max(int *,int,int,int);
void swap(int *, int, int, int,int );
using namespace std;
int main()
{
	int a[] = { 5,8,6,2,3,9,6 };
	int size = 7;
	for (int i = 0; i < 7; i++)
		cout << a[i] << " ";
	cout << endl;
	peaks_valleys(a,size);	
}
void peaks_valleys(int arr[],int len)
{
	for (int i = 1; i < len; i=i+2)
	{
		int biggest_term = max(arr,i - 1, i, i + 1);
		if (arr[i] != biggest_term)
			swap(arr, i - 1, i, i + 1,biggest_term);
	}
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int max(int *a, int l, int m, int h)
{
	int max = a[l];
	if (a[m]> max)
		max = a[m];
	if (a[h] > max)
		max = a[h];
	return max;
}
void swap(int *arr_1, int l, int m, int h, int k)
{
	if (arr_1[l] == k)
	{
		arr_1[l] = arr_1[m];
		arr_1[m] = k;
	}
	else
	{
		arr_1[h] = arr_1[m];
		arr_1[m] = k;
	}
	
}