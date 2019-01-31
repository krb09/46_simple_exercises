// CircularSortedSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int sortedsearch(int[], int,int,int);
int main()
{
	int key = 11;
	int len = 9;
	int a[] = { 10,11,12,14,1,2,3,4,5 };
	int index = sortedsearch(a, key,0,len);
	cout << index << endl;
}
int sortedsearch(int arr[], int k,int l,int h)
{
	int  middle = (l + h) / 2;
	if (arr[middle] == k)
		return middle;
	else if (arr[0] > k)
		sortedsearch(arr, k, middle + 1, h);
	else if (arr[0] < k)
		sortedsearch(arr, k, l, middle - 1);
	else
	{
		sortedsearch(arr, k, l, middle - 1);
		sortedsearch(arr, k, middle + 1, h);
	}		
}
