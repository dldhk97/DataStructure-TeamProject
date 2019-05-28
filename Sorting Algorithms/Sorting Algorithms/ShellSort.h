#pragma once
#include "Sort.h"
namespace sorts
{
	const int SIZE = 10;

	template <typename dataType>
	void shellSort(std::vector<dataType>& dataArr)
	{
		dataType temp;
		int j;
		int gap = SIZE / 2;
		while (gap > 0)
		{
			for (int i = gap; i < SIZE; i++)
			{
				temp = dataArr[i];
				j = i;
				while (j >= gap && dataArr[j - gap] > temp)
				{
					dataArr[j] = dataArr[j - gap];
					j -= gap;
				}
				dataArr[j] = temp;
			}
			gap /= 2;
		}
	}
}