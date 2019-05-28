// √‚√≥ https://github.com/hugopeixoto/mergesort/blob/master/c%2B%2B/mergesort.cpp
#pragma once
#include <iterator>
#include <queue>
namespace sorts
{
	template<typename Iterator>
	void mergeSort_(Iterator begin, Iterator end, Iterator res)
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
			mergeSort_(begin, middle, res);
			mergeSort_(middle, end, res);
			merge(begin, middle, end, res);
		}
	}

	template<typename container>
	void mergeSort(container& arr)
	{
		container temp(arr);
		mergeSort_(std::begin(arr), std::end(arr), std::begin(temp));
		std::copy(std::begin(temp), std::end(temp), std::begin(arr));
	}

	template <typename dataType>
	void nonRecursiveMergeSort(std::vector<dataType>& dataArr)
	{
		int capacity = dataArr.size();
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

	template <typename dataType>
	void merge(std::vector<dataType>& a, std::vector<dataType>& b, int l, int m, int r)
	{
		int i, j, k;
		for (i = m + 1; i > l; i--)
		{
			b[i - 1] = a[i - 1];
		}
		for (j = m; j < r; j++)
		{
			b[r + m - j] = a[j + 1];
		}
		for (k = l; k <= r; k++)
		{
			a[k] = (b[i] < b[j]) ? b[i++] : b[j--];
		}
	}

	template <typename dataType>
	void naturalMergeSort(std::vector<dataType>& arr)
	{
		int n = arr.size();
		std::queue<int> listLength;
		int length = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				listLength.push(length);
				length = 0;
			}
			length++;
			if (i == n - 2)
			{
				listLength.push(length);
			}
		}
		std::vector<dataType> mergedList(arr.size());

		//dataType* mergedList = new dataType[n];
		int index = 0;

		while (listLength.size() != 1)
		{
			int j = listLength.front();
			listLength.pop();

			if (index + j == n)
			{
				listLength.push(j);
				index = 0;
				continue;
			}

			int k = listLength.front();
			listLength.pop();

			merge(arr, mergedList, index, index + j - 1, index + j + k - 1);

			index = index + j + k;

			listLength.push(j + k);

			if (index == n)
			{
				index = 0;
			}
		}
	//	delete[] mergedList;
	}
}
