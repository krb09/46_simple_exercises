// Print_Last_K.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
void print_last_k(int[], int, int);
int main()
{
	int a[] = { 5,6,7,8,9,9,10,11 };
	int k = 4;
	int len = 7;
	print_last_k(a, k,len);
}
void print_last_k(int arr[], int n, int size)
{
	static int iter = -1;
	static int k = 0;
	if (iter == size)
	{
		return;
	}
	else
	{
		iter = iter + 1;
		print_last_k(arr, iter, size);
		if (k < n)
		{
			cout << arr[iter--] << endl;
			k = k + 1;
		}
	}
}

