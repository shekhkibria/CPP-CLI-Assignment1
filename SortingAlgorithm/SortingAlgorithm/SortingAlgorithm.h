// SortingAlgorithm.h
#pragma once

namespace SortingAlgorithm {

	public ref class Sort
	{
	public:
		virtual void sort(int *arr, int size);
	};

	public ref class MergeSort: public Sort
	{
	public:
		MergeSort();
		~MergeSort();
		void sort(int *arr, int size) override;
	};

	public ref class QuickSort: public Sort
	{
	public:
		QuickSort();
		~QuickSort();
		void sort(int *arr, int size) override;
	};

	public ref class InsertionSort : public Sort
	{
	public:
		InsertionSort();
		~InsertionSort();
		void sort(int *arr, int size) override;
	};

}
