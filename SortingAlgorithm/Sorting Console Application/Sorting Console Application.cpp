// Sorting Console Application.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include <vcclr.h>
#include <string>
#include "FileInputOutput.h"

using namespace System;
using namespace SortingAlgorithm;


class SortingFromFile
{
	gcroot<Sort^> sorting;
	FileInputOutput* fileInputOutput;
	int *arr, size;

public:
	SortingFromFile(String^ inFileName, String^ outFileName, Sort^ sort)
	{
		this->fileInputOutput = new FileInputOutput(inFileName, outFileName);
		this->sorting = sort;
		this->arr = new int[1000];
	}
	
	~SortingFromFile()
	{
		delete fileInputOutput;
		delete[] arr;
		std::cout << "Deleted native pointer upon calling this destructor" << std::endl;
	}

	void readFile()
	{
		fileInputOutput->readFile(arr);

		// Size of the array
		size = fileInputOutput->getNumberOfElements();
	}

	void writeFile()
	{
		fileInputOutput->writeFile(arr);
	}

	void printArray()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << std::endl;
		}
	}

	void sort()
	{
		std::cout << "Before sort:" << std::endl;
		printArray();

		sorting->sort(arr, size);

		std::cout << "After sort:" << std::endl;
		printArray();
	}
};
int main()
{
	String^ inputFileName , ^outputFileName ;

	Console::WriteLine("Give input file path:");
	inputFileName = Console::ReadLine();

	Console::WriteLine("Give output file path:");
	outputFileName = Console::ReadLine();

	auto sortingFromFIle = new SortingFromFile(inputFileName, outputFileName, gcnew Sort());

	sortingFromFIle->readFile();
	sortingFromFIle->sort();
	sortingFromFIle->writeFile();
	
	delete sortingFromFIle;
	std::cin.get();
    return 0;
}
