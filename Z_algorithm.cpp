// Z_algorithm.cpp 

#include "pch.h"
#include <iostream>
#include <string>
using namespace std; 
void pattern_match(string, string);
void get_arr(string,int);
int main()
{
	string a = "batman&robinro";
	string b = "ro";
	pattern_match(a, b);
}
void pattern_match(string a, string b)
{
	string z = b +"$"+ a;
	int len_z = z.length();
	for (int i = 0; i < len_z; i++)
	{
		cout << z[i] << " ";
	}
	cout << endl;
	get_arr(z, b.length());
	cout << endl;
}
void get_arr(string arr,int k_l)
{
	int len = arr.length();
	int *k = new int[len];
	int ptr = 1;
	int l = 0;
	k[0] = 0;
	while (ptr <= len)
	{
		int iter = ptr;
		while (arr[iter] == arr[l])
		{
			iter = iter + 1;
			l = l + 1;
		}
		k[ptr] = iter - ptr;
		l = 0;
		ptr = ptr + 1;
	}
	for (int i = 0; i < len; i++)
	{
		if (k[i] == k_l)
		{
			cout << "Found the substring at postion:" << (i - (1 + k_l));
			cout << endl;
		}
	}
	cout << endl;
}