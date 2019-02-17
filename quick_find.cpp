// HW_1_ques1_quickFind

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std::chrono;
using namespace std;
void generate_database(int[], int);
bool quick_find(int, int,int []);
void union_qF(int, int,int [], int );
void display(int[], int);

int main()
{
	string file_size;
	int p;
	int q;
	cout << "Enter the number of pairs in the file:";
	cin >> file_size;
	const int size = 10;
	int database[size];
	generate_database(database, size);
	string filename = file_size + "pair.txt";
	cout << filename << endl;
	ifstream read;
	auto start = high_resolution_clock::now();
	read.open(filename); while (read >> p >> q)
	{
		bool result = (quick_find(p, q, database));
		if (!result)
			union_qF(p, q, database, size);
	}
	auto end = high_resolution_clock:: now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "The duartion for quick find is:" << duration.count() << " microseconds" << endl;
	display(database, size);
	read.close();
}
bool quick_find(int p, int q,int arr[])
{
	if (arr[p] == arr[q])
		return true;
	else
		return false;
}
void union_qF(int p, int q, int arr[], int len)
{
	int k = arr[q];
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == k)
			arr[i] = arr[p];
	}
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
		cout << i<<":"<<arr[i] << endl;
	}
}
int root(int p,int arr[])
{
	while (p != arr[p])
	{
		p = arr[p];
	}
	return p;
}
void quick_union(int p, int q, int arr[], int len)
{
	arr[q] = arr[p];
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