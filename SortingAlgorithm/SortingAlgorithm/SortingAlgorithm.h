// SortingAlgorithm.h

#pragma once

using namespace System;

namespace SortingAlgorithm {
	public ref class Sort
	{
	public:
		virtual void sort(int *, int);
	};
	public ref class MergeSort: public Sort
	{
	public:
		MergeSort();
		~MergeSort();
		void sort(int *, int) override;
	};

	public ref class QuickSort: public Sort
	{
	public:
		QuickSort();
		~QuickSort();
		void sort(int *, int) override;
	};

	public ref class InsertionSort : public Sort
	{
	public:
		InsertionSort();
		~InsertionSort();
		void sort(int *, int) override;
	};
}
