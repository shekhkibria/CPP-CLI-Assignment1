// This is the main DLL file.
#include "stdafx.h"
#include<iostream>
#include "SortingAlgorithm.h"

using namespace SortingAlgorithm;


static void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort  
void Sort::sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}



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


InsertionSort::InsertionSort()
{
	std::cout << "InsertionSort sort constructor" << std::endl;
}

InsertionSort::~InsertionSort()
{
	std::cout << "InsertionSort sort destructor" << std::endl;
}


/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n);

//numbers is the pointer to an array to be sorted and size is the total size of the array
void InsertionSort::sort(int *numbers, int size)
{
	insertionSort(numbers, size);
}