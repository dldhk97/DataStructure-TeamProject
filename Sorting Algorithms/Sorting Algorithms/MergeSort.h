// √‚√≥ https://github.com/hugopeixoto/mergesort/blob/master/c%2B%2B/mergesort.cpp
#pragma once
#include <iterator>

namespace sorts
{
	template<typename Iterator>
	void mergeSort(Iterator begin, Iterator end, Iterator res)
	{
		auto merge = [](Iterator begin, Iterator middle, Iterator end, Iterator res)->void
		{
			Iterator a = begin, b = middle, r = res;

			while (a < middle && b < end)
				if (*a < *b)* r++ = *a++;
				else *r++ = *b++;

			while (a < middle) *r++ = *a++;
			while (b < end) *r++ = *b++;
			while (begin < end) *begin++ = *res++;
		};

		int s = end - begin;
		if (s > 1)
		{
			Iterator middle = begin + s / 2;
			mergeSort(begin, middle, res);
			mergeSort(middle, end, res);
			merge(begin, middle, end, res);
		}
	}

	template<typename container>
	void mergeSort(container& arr)
	{
		container temp(arr);
		mergeSort(std::begin(arr), std::end(arr), std::begin(temp));
		std::copy(std::begin(temp), std::end(temp), std::begin(arr));
	}
}
