// SparseSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int sparse_search(string[], string, int, int);
int main()
{
	string s[] = { "beg","ball","","","","cat","doll" };
	cout<<"**" <<sparse_search(s, "apple", 0, 6)<<endl;

}
int sparse_search(string arr[], string k, int l, int h)
{
	if (l > h)
		return -1;
	int mid = (l + h)/2;
	int flag = 0;
	int temp = mid;
	while (arr[mid] == "")
	{
		if (mid > l && flag == 0)
			--mid;
		else if (mid == l && flag==0)
		{
			mid = temp;
			flag = 1;
		}
		else if (flag == 1 && mid == h)
			return -2;
		else
			++mid;
	}
	if (arr[mid] == k)
	{
		return mid;
	}
	else if (k > mid[arr])
		return sparse_search(arr, k, mid + 1, h);
	else
		return sparse_search(arr, k, l, mid - 1);
}

