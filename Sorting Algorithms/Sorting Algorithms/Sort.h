#pragma once
#include "SortManager.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"

namespace utility
{
	template <typename dataType>
	void swap(dataType& data1, dataType& data2)
	{
		dataType temp = data1;
		data1 = data2;
		data2 = temp;
	}
}