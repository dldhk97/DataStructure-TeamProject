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
					utility::swap(dataArr[i], dataArr[j]);
			}
		}
	}
}