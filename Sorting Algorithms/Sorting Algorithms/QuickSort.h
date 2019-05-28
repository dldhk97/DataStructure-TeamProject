#pragma once
#include "Sort.h"

namespace sorts
{
	template <typename dataType>
	void recursiveQuickSort(std::vector<dataType>& dataArr, int start, int end)
	{
		if (start >= end)
		{
			// ���Ұ� 1���� ���
			return;
		}

		int pivot = start;
		int i = pivot + 1; // ���� ��� ���� 
		int j = end; // ������ ��� ����
		dataType temp;

		while (i <= j)
		{
			// �����Ͱ� ������������ �ݺ�
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
				// ������
				temp = dataArr[j];
				dataArr[j] = dataArr[pivot];
				dataArr[pivot] = temp;
			}
			else
			{
				// i��°�� j��°�� ����
				temp = dataArr[i];
				dataArr[i] = dataArr[j];					
				dataArr[j] = temp;
			}
		}
		// ���� ���
		recursiveQuickSort(dataArr, start, j - 1);
		recursiveQuickSort(dataArr, j + 1, end);
	}

	template <typename dataType>
	void nonRecursiveQuickSort(std::vector<dataType>& dataArr, int pivot)
	{

	}
}