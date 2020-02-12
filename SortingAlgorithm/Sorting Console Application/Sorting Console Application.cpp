// Sorting Console Application.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include <vcclr.h>
#include <string>
#include "FileInputOutput.h"

using namespace System;
using namespace SortingAlgorithm;

int arr[10000],size;

class SortingFromFile
{
	gcroot<Sort^> m_sort;
	FileInputOutput* m_finout;
public:
	SortingFromFile(String^ inFileName, String^ outFileName, Sort^ sort)
	{
		this->m_finout = new FileInputOutput(inFileName, outFileName);
		this->m_sort = sort;
	}
	
	~SortingFromFile()
	{
		delete m_finout;
		std::cout << "Deleted native pointer upon calling this destructor" << std::endl;
	}

	void sort()
	{

		std::ifstream ifs;
		ifs.open("input.txt");

		int number;
		while (ifs >> number)
			std::cout << number << std::endl;
		ifs.close();
		m_finout->readFile(arr);
		size = m_finout->getNumberOfElements(); //Size of the array

		std::cout << "Before sort:" << std::endl;
		for (int i = 0; i < 12; i++)
		{
			std::cout << arr[i] << std::endl;
		}

		m_sort->sort(arr, size);
		m_finout->writeFile(arr);
	}
};
int main()
{
	String^ inputFileName = "input.txt", ^outputFileName = "output.txt";
	auto sortingFromFIle = new SortingFromFile(inputFileName, outputFileName, gcnew QuickSort());
	sortingFromFIle->sort();

	std::cout << "After sort:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	delete sortingFromFIle;
	std::cin.get();
    return 0;
}
