#pragma once
#include "Sort.h"

namespace sorts
{
	template <typename dataType>
	void bubbleSort(std::vector<dataType>& dataArr)
	{
		for (int i = 0; i < dataArr.size(); i++)
		{
			for (int j = 0; j < dataArr.size(); j++)
			{
				if (dataArr[i] < dataArr[j])
					std::swap(dataArr[i], dataArr[j]);
			}
		}
		/*for (auto i : dataArr)
		{
			for (auto j : dataArr)
			{
				if (i < j)
					std::swap(i, j);
			}
		}*/	
	}
}