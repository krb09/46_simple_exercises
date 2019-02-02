// SortedMatrixSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "pch.h"
#include <iostream>
using namespace std;
int sortedmatrixsearch(int[][10], int);
int binary_search(int arr_1[][10], int , int , int,int );
int main()
{
	int a[10][10] = {};
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			a[i][j] = (count++) + 1;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << a[i][j]<<"  ";
		}
		cout << "\n";
	}
	int index= sortedmatrixsearch(a,35);
	if (index < 0)
		cout << "Key not found";
	else
	{
		int c = index % 10;
		int r = (index - c) / 10;
		cout << "Key at:[" << r << "," << c << "]" << endl;
	}
}
int sortedmatrixsearch(int arr[][10], int k)
{
	int index_row=0;
	int i;
	for ( i = 0; i < 10; i++)
	{
		if (arr[0][0] > k)
			return -1;
		else if(arr[0][i] == k)
			return 10*i;
		else if(arr[i][0] > k)
		{
			index_row = i;
			break;					//first time jab bada mila, find it and then stop;
		}
	}
	int index_return = binary_search(arr, k, index_row - 1, 0, 10);
	return index_return;
}
int binary_search(int arr_1[][10], int key, int row, int l,int h)
{
	if (l > h)
		return -3;
	int mid = (l + h) / 2;
	if (arr_1[row][mid] == key)
	{
		return (row*10+mid);
	}
	else if (arr_1[row][mid] < key)
		return binary_search(arr_1, key,row,mid + 1,h);
	else
		return binary_search(arr_1, key, row,l,mid - 1);
}

