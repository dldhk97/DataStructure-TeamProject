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
				std::swap(dataArr[j - 1], dataArr[j]);
				j--;
			}
		}
		//auto begin_iter = std::begin(arr);
		//auto end_iter = std::end(arr);

		//for (auto i = begin_iter; i != end_iter; ++i)
		//{
		//	if (i == begin_iter)
		//		continue;

		//	for (auto j = i; *--j > *j;)
		//	{
		//		std::swap(*j, *i);
		//	}
		//}
	}
}