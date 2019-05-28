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
	void nonRecursiveQuickSort(std::vector<dataType>& dataArr, int pivot)
	{

	}
}