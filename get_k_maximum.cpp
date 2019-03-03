// Heap_HeapSort.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int N = 0;

void swim(int k, vector<int> &a);
void sink(int k, vector<int> &a);
void insert(int key, vector<int> &a);
int del_max(vector<int> &a);
void swap(int i, int r, vector<int> &a);

int main()
{
	vector<int> heap;
	heap.push_back(-1);
	int test[] = { 5,8,7,1,4,2,6,0,3,9 };
	int size = 10;
	for (int i = 0; i < size; i++)
	{
		insert(test[i], heap);
	}
	for (int i = 1; i <= N; i++)
	{
		cout << heap[i] << " ";
	}
	cout << endl;
	const int first_K = 5;
	int result[first_K];
	for (int i = 0; i < first_K; i++)
	{
		result[i] = del_max(heap);
	}
	for (int i = 0; i < first_K; i++)
	{
		cout << result[i] << " ";
	}
}

void swim(int k, vector<int> &a)				// k--> position of the last empty space
{
	while (k > 1 && a[k] > a[k / 2])
	{
		swap(k, k / 2, a);
		k = k / 2;
	}
}
void sink(int k, vector<int> &a)
{
	int j = 2 * k;
	while (j <= N)
	{
		if (a[j] > a[j + 1] && a[j] > a[k])
		{
			swap(j, k, a);
			j = j * 2;
		}
		else if (a[j + 1] > a[j] && a[j + 1] > a[k])
		{
			swap(j + 1, k, a);
			j = j + 1;
		}
		else
			break;
	}
}
void insert(int key, vector<int> &a)
{
	a.push_back(key);
	N = N + 1;
	swim(N,a);
}
int del_max(vector<int> &a)
{
	int temp = a[1];
	swap(1, N--,a);
	sink(1, a);
	return temp;
}
void swap(int i, int r, vector<int> &a)
{
	int temp = a[i];
	a[i] = a[r];
	a[r] = temp;
}
