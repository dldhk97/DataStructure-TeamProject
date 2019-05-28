#pragma once
#include "Sort.h"
#include "Stack.h"

namespace sorts
{
	template <typename dataType>
	void recursiveQuickSort_(std::vector<dataType>& dataArr, int start, int end)
	{
		if (start >= end)
		{
			// 원소가 1개인 경우
			return;
		}

		int pivot = start;
		int i = pivot + 1; // 왼쪽 출발 지점 
		int j = end; // 오른쪽 출발 지점
		dataType temp;

		while (i <= j)
		{
			// 포인터가 엇갈릴때까지 반복
			while (i <= end && dataArr[i] <= dataArr[pivot])
			{
				i++;
			}
			while (j > start && dataArr[j] >= dataArr[pivot])
			{
				j--;
			}

			if (i > j)
			{
				// 엇갈림
				temp = dataArr[j];
				dataArr[j] = dataArr[pivot];
				dataArr[pivot] = temp;
			}
			else
			{
				// i번째와 j번째를 스왑
				temp = dataArr[i];
				dataArr[i] = dataArr[j];					
				dataArr[j] = temp;
			}
		}
		// 분할 계산
		recursiveQuickSort_(dataArr, start, j - 1);
		recursiveQuickSort_(dataArr, j + 1, end);
	}

	template <typename dataType>
	void recursiveQuickSort(std::vector<dataType>& dataArr)
	{
		recursiveQuickSort_(dataArr, 0, dataArr.size() - 1);
	}

	template <typename dataType>
	void recursiveQuickSort_median_(std::vector<dataType>& dataArr, int start, int end)
	{
		if (start >= end)
		{
			// 원소가 1개인 경우
			return;
		}

		//dataArr.swap(start, sorts::medianOfThree(dataArr, start, end));
		std::swap(dataArr[start], dataArr[sorts::medianOfThree(dataArr, start, end)]);
		int pivot = start;
		
		int i = pivot + 1; // 왼쪽 출발 지점 
		int j = end; // 오른쪽 출발 지점
		dataType temp;

		while (i <= j)
		{
			// 포인터가 엇갈릴때까지 반복
			while (i <= end && dataArr[i] <= dataArr[pivot])
			{
				i++;
			}
			while (j > start && dataArr[j] >= dataArr[pivot])
			{
				j--;
			}

			if (i > j)
			{
				// 엇갈림
				temp = dataArr[j];
				dataArr[j] = dataArr[pivot];
				dataArr[pivot] = temp;
			}
			else
			{
				// i번째와 j번째를 스왑
				temp = dataArr[i];
				dataArr[i] = dataArr[j];
				dataArr[j] = temp;
			}
		}
		// 분할 계산
		recursiveQuickSort_(dataArr, start, j - 1);
		recursiveQuickSort_(dataArr, j + 1, end);
	}

	template <typename dataType>
	void recursiveQuickSort_median(std::vector<dataType>& dataArr)
	{
		recursiveQuickSort_median_(dataArr, 0, dataArr.size() - 1);
	}
	
	template <typename dataType>
	int medianOfThree(std::vector<dataType>& dataArr, int start, int end)
	{
		if (dataArr[0] < dataArr[end / 2] && dataArr[end / 2] < dataArr[end])
			return end / 2;

		if (dataArr[end] < dataArr[end / 2] && dataArr[end / 2] < dataArr[0])
			return end / 2;

		if (dataArr[end/2] < dataArr[0] && dataArr[0] < dataArr[end])
			return 0;

		if (dataArr[end] < dataArr[0] && dataArr[0] < dataArr[end/2])
			return 0;

		if (dataArr[0] < dataArr[end] && dataArr[end] < dataArr[end / 2])
			return end;

		if (dataArr[0] < dataArr[end] && dataArr[end] < dataArr[end / 2])
			return end;
		return start;
	}

	template <typename dataType>
	void nonRecursiveQuickSort(std::vector<dataType>& dataArr) 
	{
		const int size = dataArr.size();
		Stack<int> stk;
		dataType pivot;
		int left, right, median;
		int i, j;

		left = 0;
		right = size - 1;
		median = left + (right - left) / 2;

		stk.push(right); stk.push(left);
		while (!stk.isEmpty()) 
		{
			left = stk.peek();
			stk.pop();
			right = stk.peek();
			stk.pop();

			while (left < right) 
			{
				median = left + (right - left) / 2;

				sorts::sort_of_three_key(dataArr, left, median, right);
				pivot = dataArr[median];
				dataArr[median] = dataArr[left];
				dataArr[left] = pivot;

				i = left;
				j = right + 1;

				while (true) 
				{
					while (dataArr[++i] < pivot && i < dataArr.size() - 1);
					while (pivot < dataArr[--j]);

					if (j <= i)
						break;
					std::swap(dataArr[i], dataArr[j]);
				}

				dataArr[left] = dataArr[j];
				dataArr[j] = pivot;

				if (i < right) 
				{
					stk.push(right);
					stk.push(i);
				}
				right = j - 1;
			}
		}
	}

	template <typename dataType>
	void sort_of_three_key(std::vector<dataType> dataArr, int left, int middle, int right) 
	{
		if (dataArr[left] > dataArr[middle])
		{
			std::swap(dataArr[left], dataArr[middle]);
		}
		if (dataArr[middle] > dataArr[right])
		{
			std::swap(dataArr[right], dataArr[middle]);
		}
		if (dataArr[left] > dataArr[middle])
		{
			std::swap(dataArr[left], dataArr[middle]);
		}
	}
}