#pragma once
#include <vector>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "RadixSort10.h"
#include "RadixSort16.h"
#include "RadixSortMasking.h"

//디버깅용 출력코드
namespace sorts
{
	template <typename dataType>
	void displayArr(std::vector<dataType>& dataArr)
	{
		for (auto elem : dataArr)
		{
			std::cout << elem << "\n";
		}
	}
}