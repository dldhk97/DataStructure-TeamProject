#pragma once
#include <iterator>
#include <list>

namespace sorts
{
	/*template <typename dataType>
	void insertionSort(std::vector<dataType>& dataArr)
	{
		int i, j;
		dataType temp;
		for (i = 1; i < dataArr.size(); i++)
		{
			temp = dataArr[(j = i)];
			while (--j >= 0 && temp < dataArr[j])
			{
				dataArr[j + 1] = dataArr[j];
				dataArr[j] = temp;
			}
		}
	}*/

	//template<typename Container>
	//void insertionSort(Container& container)
	//{
	//	auto forward_iter = std::begin(container);
	//	auto temp_iter = std::end(container);
	//	auto begin_iter = std::begin(container);
	//	auto end_iter = std::end(container);

	//	do {
	//		temp_iter = forward_iter;
	//		auto temp_value = *temp_iter;

	//		if (temp_iter == begin_iter)
	//		{
	//			continue;
	//		}
	//		while (--temp_iter != begin_iter && temp_value < *temp_iter)
	//		{
	//			*std::next(temp_iter) = *temp_iter;
	//			*temp_iter = temp_value;
	//		}
	//	} while (++forward_iter != end_iter);
	//}

	template<typename Container>
	void insertionSort(Container& container)
	{
		auto first = std::begin(container);
		auto last = std::end(container);

		for (auto it = first; it != last; ++it)
			std::rotate(std::upper_bound(first, it, *it), it, std::next(it));
	}

	/*template <typename dataType>
	void insertionSort_list(std::list<dataType>& dataList)
	{
		for (auto j = 1U; j < dataList.size(); ++j)
		{
			auto itr = dataList.begin();
			std::advance(itr, j);
			const auto key = *itr;

			for (auto i = j; i > 0U; --i)
			{
				std::advance(itr, -1);

				if (key < *itr)
				{
					const dataType temp = *itr;
					*itr = key;
					*std::next(itr) = temp;
				}
				else
				{
					break;
				}
			}
		}
	}*/

}