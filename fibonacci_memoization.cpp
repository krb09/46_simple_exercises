// fibonacci_memoization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int fibonacci_1(int);
int fibonacci(int, int []);

int main()
{
	int fib = 6;
	cout<<fibonacci_1(fib)<<endl;
}
int fibonacci_1(int n)
{
	int *mem = new int[n];
	mem[0] = 1;
	mem[1] = 1;
	for (int i = 2; i < n + 1; i++)
		mem[i] = 0;
	return fibonacci(n,mem);
}
int fibonacci(int i, int mem[])
{
	if (i == 1 || i == 0)
		return 1;
	if (mem[i] == 0) 
	{
		mem[i] = fibonacci(i - 1, mem) + fibonacci(i - 2, mem);
	}
	return mem[i];
}