#pragma once
#include <iterator>
#include <algorithm>

namespace sorts
{
	template<typename container>
	void selectionSort(container& arr)
	{
		auto begin_iter = std::begin(arr);
		auto end_iter = std::end(arr);
		auto min_iter = std::begin(arr);

		do {
			min_iter = std::min_element(begin_iter, end_iter);
			std::swap(*min_iter, *begin_iter);
			++begin_iter;
		} while (begin_iter != end_iter);
	}
}