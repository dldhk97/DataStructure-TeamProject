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
			// ���Ұ� 1���� ���
			return;
		}

		//dataArr.swap(start, sorts::medianOfThree(dataArr, start, end));
		std::swap(dataArr[start], dataArr[sorts::medianOfThree(dataArr, start, end)]);
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
	void nonRecursiveQuickSort(std::vector<dataType>& dataArr)
	{
		// ����Ʈ �Լ�
		int start = 0;
		int end = dataArr.size();

		int i, j;
		dataType pivot;
		Stack<int> stack;

		// ���ÿ� �ִ´�

		stack.push(end);
		stack.push(start);

		// ������ ������ �� ���� ������ ����Ѵ�
		while (stack.isEmpty())
		{
			start = stack.pop();
			end = stack.pop();

			pivot = dataArr[0];
			i = start;
			j = end;

			// �ش� �κ� ���� �Ϸ�
			if (end - start < 2)
				continue;

			// i�� j�� ������ �� ���� i�ϰ� j���� ��� �ٲ۴�
			while (i < j)
			{
				do
				{
					i++;
				} while (dataArr[i] < pivot);
				do
				{
					j--;
				} while (dataArr[j] > pivot);
				// i�� j���� ������ i���ϰ� j�� ��ȯ
				if (i < j)
				{
					std::swap(dataArr[i], dataArr[j]);
				}
			}
			// i�� j�� �����ϸ� �Ǻ����ϰ� j�� ��ȯ

			std::swap(dataArr[start], dataArr[j]);

			// j�ڸ��ϰ� �ٲ� �Ǻ����� ��,�� ���Ŀ� ���� ���� ���ÿ� �ִ´�.
			stack.push(end);
			stack.push(j + 1);
			stack.push(j);
			stack.push(start);
		}
	}
}