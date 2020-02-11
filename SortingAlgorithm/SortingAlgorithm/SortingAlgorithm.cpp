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



QuickSort::QuickSort()
{
	std::cout << "Quick sort constructor" << std::endl;
}

QuickSort::~QuickSort()
{
	std::cout << "Quick sort destructor" << std::endl;
}


/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quickSort(int arr[], int low, int high);

//numbers is the pointer to an array to be sorted and size is the total size of the array
void QuickSort::sort(int *numbers, int size)
{
	quickSort(numbers, 0, size - 1);
}