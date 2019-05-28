#pragma once
#include "Sort.h"

namespace sorts
{
	template <typename dataType>
	void recursiveQuickSort(std::vector<dataType>& dataArr, int start, int end)
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
		recursiveQuickSort(dataArr, start, j - 1);
		recursiveQuickSort(dataArr, j + 1, end);
	}

	template <typename dataType>
	void recursiveQuickSort_median(std::vector<dataType>& dataArr, int start, int end)
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
		recursiveQuickSort(dataArr, start, j - 1);
		recursiveQuickSort(dataArr, j + 1, end);
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
	}

	template <typename dataType>
	void nonRecursiveQuickSort(std::vector<dataType>& dataArr, int pivot)
	{

	}
}