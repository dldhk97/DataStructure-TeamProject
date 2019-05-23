#pragma once
#include "Sort.h"

namespace sorts
{
	template <typename dataType>
	void insertionSort(std::vector<dataType>& dataArr)
	{
		int j;
		for (int i = 0; i < dataArr.size(); i++)
		{
			j = i;
			while (j > 0 && dataArr[j - 1] > dataArr[j])
			{
				utility::swap(dataArr[j - 1], dataArr[j]);
				j--;
			}
		}
	}
}