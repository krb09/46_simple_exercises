// Practice_Switch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int greatest_divisor(int,int);
int main()
{
	const int n=5;
	int *a = new int[n];
	cout << "Enter the array elements,press -1 to discontinue:" << endl;
	int input=0;
	int j = 0;
	while (j<n)
	{
		cin >> input;
		a[j++]=input;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	int k;
	for (int i = 0; i < n-1; i++)
	{
		k = greatest_divisor(a[i], a[i + 1]);
		if (k == -1)
			break;
		a[i + 1] = k;
	}
	if (k == -1)
		cout << "Greatest common divisor is:" << 1 << endl;
	else
		cout << "Greatest common divisor is:" << k << endl;
}
int greatest_divisor(int a,int b)
{
	if (a == 0 || b == 0)
		return -1;
	else if (a>b && a%b == 0)
	{
		return b;
	}
	else if (b>a && b%a == 0)
	{
		return a;
	}
	else
		return -1;
}