// tripleStep.cpp

#include "pch.h"
#include <iostream>
using namespace std;
int tripleStep_1(int);
int tripleStep(int, int[]);

int main()
{
	int key = 5;
	cout<<tripleStep_1(key)<<endl;
}
int tripleStep_1(int n)
{
	int *mem = new int[n+1];
	mem[0] = 0;
	mem[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		mem[i] = 0;
	}
	return tripleStep(n, mem);
}
int tripleStep(int i, int mem[])
{
	if (i == 0)
		return 1;
	if (i == 1)
		return 1;
	if (i < 0)
		return 0;
	if (mem[i] == 0)
		mem[i] = tripleStep(i - 1,mem) + tripleStep(i - 2,mem) + tripleStep(i - 3,mem);
	return mem[i];
}

