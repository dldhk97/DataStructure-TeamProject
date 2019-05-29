#pragma once
#include "Sort.h"

namespace sorts
{
	template <typename dataType>
	void bubbleSort(std::vector<dataType>& dataArr)
	{
		/*for (int i = 0; i < dataArr.size(); i++)
		{
			for (int j = 0; j < dataArr.size(); j++)
			{
				if (dataArr[i] < dataArr[j])
					std::swap(dataArr[i], dataArr[j]);
			}
		}*/
		int size = dataArr.size();
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - 1 - i; j++) {
				if (dataArr[j] > dataArr[j + 1]) {
					std::swap(dataArr[j], dataArr[j + 1]);
				}
			}
		}
	}
}