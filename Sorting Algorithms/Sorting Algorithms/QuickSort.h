#pragma once
#include "Stack.h"

namespace sorts
{
	// https://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/

	template<typename dataType>
	int partition_(std::vector<dataType>& arr, int low, int high)
	{
		dataType pivot = arr[high];    // pivot 
		int i = (low - 1);  // Index of smaller element 

		for (int j = low; j <= high - 1; j++)
		{
			// If current element is smaller than or 
			// equal to pivot 
			if (arr[j] <= pivot)
			{
				++i;    // increment index of smaller element 
				std::swap(arr[i], arr[j]);
			}
		}
		std::swap(arr[i + 1], arr[high]);
		return (i + 1);
	}
	
	template<typename dataType>
	void quickSort_(std::vector<dataType>& arr, int low, int high)
	{
		while (low < high)
		{
			/* pi is partitioning index, arr[p] is now
			   at right place */
			int pi = partition_(arr, low, high);

			// If left part is smaller, then recur for left 
			// part and handle right part iteratively 
			if (pi - low < high - pi)
			{
				quickSort_(arr, low, pi - 1);
				low = pi + 1;
			}

			// Else recur for right part 
			else
			{
				quickSort_(arr, pi + 1, high);
				high = pi - 1;
			}
		}
	}

	template<typename dataType>
	void quickSort(std::vector<dataType>& arr)
	{
		quickSort_(arr, 0, arr.size() - 1);
	}

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
		if (dataArr[end / 2] <= dataArr[end] && dataArr[end] <= dataArr[0])
		{
			return end;
		}
		if (dataArr[end / 2] <= dataArr[0] && dataArr[0] <= dataArr[end])
		{
			return 0;
		}
		if (dataArr[end] <= dataArr[end / 2] && dataArr[end / 2] <= dataArr[0])
		{
			return end / 2;
		}
		if (dataArr[end] <= dataArr[0] && dataArr[0] <= dataArr[end / 2])
		{
			return 0;
		}
		if (dataArr[0] <= dataArr[end] && dataArr[end] <= dataArr[end / 2])
		{
			return end;
		}
		if (dataArr[0] <= dataArr[end / 2] && dataArr[end / 2] <= dataArr[end])
		{
			return end / 2;
		}
		std::cout << "error!" << std::endl;
	}

	template <typename dataType>
	void sort_of_three_key(std::vector<dataType>& dataArr, int left, int middle, int right)
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

	template <typename dataType>
	void nonRecursiveQuickSort(std::vector<dataType>& arr)
	{
		int n = arr.size();
		Stack<int> stk;
		dataType pivot;
		int left, right, median;
		int i, j;

		left = 0;
		right = n - 1;

		stk.push(right); stk.push(left);
		while (!stk.isEmpty()) {
			left = stk.pop();
			right = stk.pop();

			while (left < right) {
				median = left + (right - left) / 2;

				sort_of_three_key(arr, left, median, right);
				pivot = arr[median];
				arr[median] = arr[left];
				arr[left] = pivot;

				i = left;
				j = right + 1;

				while (true) {
					while (arr[++i] < pivot);
					while (pivot < arr[--j]);

					if (j <= i)
						break;

					std::swap(arr[i], arr[j]);
				}

				arr[left] = arr[j];
				arr[j] = pivot;

				if (i < right) {
					stk.push(right);
					stk.push(i);
				}
				right = j - 1;
			}
		}
	}
}