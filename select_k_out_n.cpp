// select_k_out_n.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int k_n(int, int);
int main()
{
	int total = 10;
	int choose = 5;
	cout << "Number of ways to choose " << choose << " out of " << total << " is:" << k_n(total, choose) << endl;
}
int k_n(int n, int k)
{
	if (k == n || k==0)
		return 1;
	else if (k > n)
		return 0;
	else
	{
		return k_n(n - 1, k - 1) + k_n(n - 1, k);
	}
}
