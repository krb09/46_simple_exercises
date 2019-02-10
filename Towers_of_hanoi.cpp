// Stack_implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Stack.h"
void tower_of_hanoi(int,Stack* , Stack* , Stack* );	//the number of elements adn towers
int main()
{
	Stack towerA(4);
	Stack towerB(4);
	Stack towerC(4);
	towerB.print_stack();
	towerA.push(4);
	towerA.push(3);
	towerA.push(2);
	towerA.push(1);
	tower_of_hanoi(4, &towerA, &towerB, &towerC);
	towerB.print_stack();
}
void tower_of_hanoi(int elements, Stack *source, Stack *destination, Stack *spare)
{
	if (elements == 1)
	{
		int temp = source->pop();
		destination->push(temp);
	}
	else
	{
		tower_of_hanoi(elements-1,source,spare,destination);
		tower_of_hanoi(1, source, destination,spare);
		tower_of_hanoi(elements - 1, spare, destination, source);
	}
}

