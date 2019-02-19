// List_of_primes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<cmath>
using namespace std; 
void setFlags(bool[], int,int);
int return_prime(bool[], int,int);
int main()
{
	const int size = 100;
	bool list_primes[size];
	for (int i = 0; i < 100; i++)
		list_primes[i] = true;
	list_primes[0] = false;			//both 0 and 1 are not primes
	list_primes[1] = false;				
	int prime = 2;
	
	while (prime <= sqrt(size))
	{
		setFlags(list_primes, prime,size);
		prime = return_prime(list_primes, prime,size);
	}
	for (int i = 2; i < size; i++)
	{
		if (list_primes[i] == true)
			cout << i << " ";
	}
}
void setFlags(bool arr[], int p,int len)
{
	for (int i = p * p; i < len; i = i + p)
	{
		arr[i] = false;
	}
}
int return_prime(bool arr[], int p, int len)
{
	for (int i = p + 1; i < len; i++)
	{
		if (arr[i] == true)
			return i;
	}
}