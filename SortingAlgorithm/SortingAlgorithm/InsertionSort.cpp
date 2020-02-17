#include "stdafx.h"
#include "SortingAlgorithm.h"
#include <iostream>

using namespace SortingAlgorithm;

InsertionSort::InsertionSort()
{
	std::cout << "InsertionSort sort constructor" << std::endl;
}

InsertionSort::~InsertionSort()
{
	std::cout << "InsertionSort sort destructor" << std::endl;
}

/* Function to sort an array using insertion sort*/
void InsertionSort::sort(int *arr, int size)
{
	int i, key, j;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
