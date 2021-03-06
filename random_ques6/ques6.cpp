/*Ques 6: Define a function sum()and a function multiply()that sums and multiplies (respectively) all the
numbers in a list of numbers. For example, sum([1, 2, 3, 4])should return 10, and multiply([1,
2, 3, 4])should return 24.*/

#include "pch.h"
#include <iostream>
#include<vector>
#include<iterator>
using namespace std;
double sum(vector<double> *);
double multiply(vector<double> *);
int main()
{
	vector<double> result;
	cout << "Enter the numbers, enter -1 to quit: ";
	istream_iterator<double> input(cin);
	while (*input != -1)
	{
		result.push_back(*input);
		++input;
	}
	double k = sum(&result);
	double k1 = multiply(&result);
	cout << "The sum of numbers is: " << k << endl;
	cout << "The product of numbers is: " << k1 << endl;
}
double sum(vector<double> *a)
{
	double sum = 0;
	for (int i = 0; i < a->size(); i++)
	{
		sum = sum + (*a)[i];
	}
	return sum;
}
double multiply(vector<double> *a)
{
	double product = 1; 
	for (int i = 0; i < a->size(); i++)
	{
		product = product * (*a)[i];
	}
	return product;
}

