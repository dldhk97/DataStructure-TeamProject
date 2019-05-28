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

	template <typename dataType>
	void nonRecursiveMergeSort(std::vector<dataType>& dataArr, const int capacity)
	{
		for (int n = 2; n / 4 < capacity / 2; n *= 2)
		{
			for (int i = 0; i < capacity; i += n)
			{
				if (n == 2)
				{
					if (i + 1 < capacity && dataArr[i + 1] < dataArr[i])
						std::swap(dataArr[i], dataArr[i + 1]);
				}
				else
				{
					std::vector<dataType> tempArr;

					int k = 0, l = i, m = i + n / 2;
					while (m < capacity && l < i + n / 2 && m < i + n)
					{
						if (l < i + n / 2 && dataArr[l] < dataArr[m])
							tempArr.push_back(dataArr[l++]);
						else
							tempArr.push_back(dataArr[m++]);
					}
					while (l < capacity && l < i + n / 2)
					{
						tempArr.push_back(dataArr[l++]);
					}
					while (m < capacity && m < i + n)
					{
						tempArr.push_back(dataArr[m++]);
					}

					for (int o = i; o < i + n; o++)
					{
						if (capacity - 1 < o) break;
						dataArr[o] = tempArr[o - i];
					}
				}
			}
		}
	}

}
