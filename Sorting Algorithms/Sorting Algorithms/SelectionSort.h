#pragma once
#include <iterator>
#include <algorithm>

namespace sorts
{
	template<typename dataType>		//보통 선택정렬
	void selectionSort(dataType& dataArr)
	{
		int indexMin, size = dataArr.size();

		for (int i = 0; i < size - 1; i++)
		{
			indexMin = i;
			for (int j = i + 1; j < size; j++)
			{
				if (dataArr[j] < dataArr[indexMin])
				{
					indexMin = j;
				}
			}
			std::swap(dataArr[indexMin], dataArr[i]);
		}
	}

	//template<typename dataType>		//최속의 선택정렬
	//void selectionSort(dataType& dataArr)
	//{
	//	auto begin_iter = std::begin(dataArr);
	//	auto end_iter = std::end(dataArr);
	//	auto min_iter = std::begin(dataArr);

	//	do {
	//		min_iter = std::min_element(begin_iter, end_iter);
	//		std::swap(*min_iter, *begin_iter);
	//		++begin_iter;
	//	} while (begin_iter != end_iter);
	//}
}