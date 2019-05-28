#pragma once
#include "Sort.h"
#include <list>
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
	}

	template <typename dataType>
	void insertionSort_list(std::vector<dataType>& dataArr)
	{
		std::list<dataType> temp;
		for (int i = 0; i < dataArr.size(); i++)
		{
			temp.push_front(dataArr[i]);
		}
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
	}
}