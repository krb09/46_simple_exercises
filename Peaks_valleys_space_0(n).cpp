// Peaks_valleys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
void peaks_valleys(int[]);
void sort(int *);
using namespace std;
int main()
{
	int a[] = { 5,8,6,2,3,9,6 };
	for (int i = 0; i < 7; i++)
		cout << a[i] << " ";
	cout << endl;
	peaks_valleys(a);	
}
void peaks_valleys(int arr[])
{
	sort(arr);
	int temp[7];
	int l = 0, h = 6,k=0;
	while (l <= h)
	{
		if (l == h)
		{
			temp[k] = arr[l];
			l++;
			h--;
		}
		else
		{
			temp[k++] = arr[h--];
			temp[k++] = arr[l++];
		}
	}
	for (int i = 0; i < 7; i++)
		cout << temp[i] << " ";
	cout << endl;
}
void sort(int *arr_1)
{
	for(int i=0;i<6;i++)
		for (int j = 1; j < 7-i; j++)
		{
			if (arr_1[j-1] > arr_1[j])
			{
				int temp = arr_1[j];
				arr_1[j] = arr_1[j-1];
				arr_1[j-1] = temp;
			}
		}
	for (int i = 0; i < 7; i++)
		cout << arr_1[i] << " ";
	cout << endl;
}