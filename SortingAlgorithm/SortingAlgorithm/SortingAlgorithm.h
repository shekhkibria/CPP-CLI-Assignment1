// SortingAlgorithm.h

#pragma once

using namespace System;

namespace SortingAlgorithm {
	public ref class Sort
	{
	public:
		virtual void sort(int *, int)=0;
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
}
