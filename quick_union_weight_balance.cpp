// quick_union_weight_balance.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include<chrono>

using namespace std;
using namespace std::chrono;
void generate_database(int[], int);
void quick_union_weighted(int, int, int[], int[]);
bool find_qU(int, int, int[], int);
void display(int[], int);

int main()
{
	string file_size;
	int p;
	int q;
	cout << "Enter the number of pairs in the file:";
	cin >> file_size;
	const int size = 10;
	int sz[size] = { 1 };
	int database[size];
	generate_database(database, size);
	string filename = file_size + "pair.txt";
	cout << filename << endl;
	ifstream read;
	auto start = high_resolution_clock::now();
	read.open(filename); while (read >> p >> q)
	{
		bool result = find_qU(p, q, database, size);
		if (!result)
			(quick_union_weighted(p, q, database,sz));
	}
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "Time for quick-union-weight-balance is:" << duration.count() << " microseconds" << endl;
	display(database, size);
	read.close();
}
void generate_database(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		arr[i] = i;
}
void display(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << i << ":" << arr[i] << endl;
	}
}
int root(int p, int arr[])
{
	while (p != arr[p])
	{
		p = arr[p];
	}
	return p;
}
void quick_union_weighted(int p, int q, int arr[], int sz[])
{
	int p_root = root(p, arr);
	int q_root = root(q, arr);
	if (sz[p] > sz[q])
	{
		arr[q_root] = p_root;
		sz[p_root] = sz[p_root] + sz[q_root];
	}
	else
	{
		arr[p_root] = arr[q_root];
		sz[q_root] = sz[q_root] + sz[p_root];
	}
}
bool find_qU(int p, int q, int arr[], int len)
{
	int p_root = root(p, arr);
	int q_root = root(q, arr);
	if (p_root == q_root)
		return true;
	else
		return false;
}