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
		int start = 0;					//custom
		int end = dataArr.size();		//custom

		int i, j;
		dataType pivot;
		Stack<int> stack;

		// ���ÿ� �ִ´�
		//stack.arr[++stack.top] = end;
		//stack.arr[++stack.top] = start;

		stack.push(end);				//custom
		stack.push(start);				//custom

		// ������ ������ �� ���� ������ ����Ѵ�
		while (stack.isEmpty())
		{
			//start = stack.arr[stack.top--];
			//end = stack.arr[stack.top--];

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
					//temp = arr[i];
					//arr[i] = arr[j];
					//arr[j] = temp;

					std::swap(dataArr[i], dataArr[j]);		//custom
				}
			}
			// i�� j�� �����ϸ� �Ǻ����ϰ� j�� ��ȯ

			//temp = arr[start];
			//arr[start] = arr[j];
			//arr[j] = temp;

			std::swap(dataArr[start], dataArr[j]);			//custom

			// j�ڸ��ϰ� �ٲ� �Ǻ����� ��,�� ���Ŀ� ���� ���� ���ÿ� �ִ´�.

			//stack.arr[++stack.top] = end;
			//stack.arr[++stack.top] = j + 1;
			//stack.arr[++stack.top] = j;
			//stack.arr[++stack.top] = start;

			stack.push(end);
			stack.push(j + 1);
			stack.push(j);
			stack.push(start);
		}
	}



	/*template <typename dataType>
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
	}*/

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