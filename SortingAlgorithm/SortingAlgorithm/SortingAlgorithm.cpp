// This is the main DLL file.
#include "stdafx.h"
#include<iostream>
#include "SortingAlgorithm.h"

using namespace SortingAlgorithm;

MergeSort::MergeSort()
{
	std::cout << "Merge sort constructor" << std::endl;
}

MergeSort::~MergeSort()
{
	std::cout << "Merge sort destructor" << std::endl;
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r);

//numbers is the pointer to an array to be sorted and size is the total size of the array
void MergeSort::sort(int *numbers, int size)
{
	mergeSort(numbers, 0, size - 1);
}

