// Sorting Console Application.cpp : main project file.
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include <vcclr.h>
#include <vector>
#include <string>
#include "FileInputOutput.h"

using namespace System;
using namespace std;
using namespace SortingAlgorithm;

class SortingFromFile
{
	gcroot<Sort^> sort;
	FileInputOutput* fileInputOutput;
	vector<int> arr;

public:

	SortingFromFile(string inputFileName, string outputFileName, Sort^ sort)
	{
		this->fileInputOutput = new FileInputOutput(inputFileName, outputFileName);
		this->sort = sort;
	}
	
	~SortingFromFile()
	{
		delete fileInputOutput;
		std::cout << "Deleted native pointer upon calling this destructor" << std::endl;
	}

	void readFile()
	{
		fileInputOutput->readFile(arr);
	}

	void writeFile()
	{
		fileInputOutput->writeFile(arr);
	}

	void printArray()
	{
		for (int number: arr)
		{
			std::cout << number << std::endl;
		}
	}

	void sortNumber()
	{
		std::cout << "Before sort:" << std::endl;
		printArray();

		// Need to create temporary array as vector or any native class can't be passed into other project's function.
		int *arrTemp = new int[arr.size()];
		for (int i = 0; i < arr.size(); i++)
			arrTemp[i] = arr[i];

		sort->sort(arrTemp, arr.size());

		/// Copy the sorted temp array back into the member vector arr
		for (int i = 0; i < arr.size(); i++)
			arr[i] = arrTemp[i];

		delete[] arrTemp;
		std::cout << "After sort:" << std::endl;
		printArray();
	}
};


int main()
{
	string inputFileName, outputFileName;

	cout << "Give input file path:" << endl;
	getline(cin , inputFileName);
	// Converting native to managed string
	String ^str="";
	for (int i=0; i<inputFileName.size();i++)
	{
		str += Char(inputFileName[i]);
	}
	if (!IO::File::Exists(str))
	{
		cout << "Input File or File path doesn't exist" << endl;
		return 0;
	}

	cout << "Give output file path:" << endl;
	getline(cin, inputFileName);
	// Converting native to managed string
	str = "";
	for (int i = 0; i<outputFileName.size(); i++)
	{
		str += Char(outputFileName[i]);
	}
	if (!IO::File::Exists(str))
	{
		cout << "Output File or File path doesn't exist" << endl;
		return 0;
	}

	cout << "Select sorting algorithm type:" << endl;
	cout << "1 for basic bubble sort" << endl;
	cout << "2 for insertion sort" << endl;
	cout << "3 for quick sort" << endl;
	cout << "4 for merge sort" << endl;
	int sortingAlgorithmType;
	cin >> sortingAlgorithmType;

	Sort ^sort;
	if (sortingAlgorithmType == 1)
		sort = gcnew Sort();
	else if (sortingAlgorithmType == 2)
		sort = gcnew InsertionSort();
	else if (sortingAlgorithmType == 3)
		sort = gcnew QuickSort();
	else
		sort = gcnew MergeSort();

	auto sortingFromFIle = new SortingFromFile(inputFileName, outputFileName, sort);

	sortingFromFIle->readFile();
	sortingFromFIle->sortNumber();
	sortingFromFIle->writeFile();
	
	delete sortingFromFIle;
	std::cin.get();
    return 0;
}
