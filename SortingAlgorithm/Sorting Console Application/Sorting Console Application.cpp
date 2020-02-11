// Sorting Console Application.cpp : main project file.

#include "stdafx.h"
#include<iostream>

using namespace System;
using namespace SortingAlgorithm;
int main()
{
    Console::WriteLine(L"Hello World");
	int n;
	//std::cin.get();

	int arr[] = { 4,5,3,2,6,7,4,5,9,8,5,3 };
	/*MergeSort^ msort=gcnew MergeSort();
	msort->sort(arr,12);*/
	Sort^ qsort = gcnew QuickSort();
	qsort->sort(arr, 12 );
	for (int i = 0; i < 12; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	std::cin.get();
    return 0;
}
