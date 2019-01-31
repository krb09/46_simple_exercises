// SortedSearch_NoSize.cpp

#include "pch.h"
#include <iostream>
using namespace std;
int find_length(int [], int,int,int);
int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10,20,22,23,- 1,-1,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 };
	int key = 23;
	int index = find_length(a, 0,0,key);
	cout << index << endl;
}
int find_length(int arr[], int l,int prev, int k)
{
	if (l==0)
	{
		if (arr[l] == -1)
			return 0;
		else if (arr[l] == k)
			return l;
		else
		{
			prev = l;
			l = l + 2;
			find_length(arr, l, prev,k);
		}
	}
	else if (arr[l] != -1)
	{
		if (arr[l] == k)
			return l;
		else if (arr[l] < k)				//the key is still on the right side
		{
			prev = l;
			l = l * 2;
			find_length(arr, l, prev, k);
		}
		else                                //key is on the left side, search
		{
			for (int i = prev; i < l; i++)
			{
				if (arr[i] != -1 && arr[i + 1] == -1)
					return i;
			}
		}
	}
	else                              //You have found the end, the key is in between this and the last index form which you doubled
	{
		for (int i = prev; i < l; i++)
		{
			if (arr[i] != -1 && arr[i + 1] == -1)
				return i;
		}
	}
}

