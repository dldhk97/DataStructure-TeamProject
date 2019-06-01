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

		// std::upper_bound : 지정한 iterator를 순회하면서 *it값을 넘어가는 지점을 이진 탐색함. 그리고 그 위치(iterator) 반환. stable함
		// std::rotate : 원소들을 (왼쪽으로) shift 하고 왼쪽 넘어간 애들은 오른쪽 끝으로 넣음

		// 처음~처음 부터 처음~끝 까지 루프를 돈다
		// 처음~it 안 루프에서 *it보다 큰 값 찾으면 그 위치 U부터 it까지의 값을 U부터 U+1 범위 내에서 rotate 
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