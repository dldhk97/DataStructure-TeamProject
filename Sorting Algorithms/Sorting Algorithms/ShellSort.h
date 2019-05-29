#pragma once
#include "Sort.h"
namespace sorts
{
	// ���� �ε��� first ���� �����ϴ� �κи���Ʈ�� ������ ���� ������ �����Ѵ�.
	template <typename dataType>
	void insertionSortForGap(std::vector<dataType>& dataArr, int first, int last, int gap)
	{
		int i, j;

		dataType key;

		for (i = first + gap; i <= last; i = i + gap)
		{
			key = dataArr[i]; // ���� ���Ե� ������ i��° ������ key ������ ����

			// ���� ���ĵ� �迭�� i-gap�����̹Ƿ� i-gap��°���� �������� �����Ѵ�.
			// j ���� first �̻��̾�� �ϰ�
			// key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+gap��°�� �̵�
			for (j = i - gap; j >= first && dataArr[j] > key; j = j - gap)
			{
				dataArr[j + gap] = dataArr[j]; // ���ڵ带 gap��ŭ ���������� �̵�
			}

			dataArr[j + gap] = key;
		}
	}

	template <typename dataType>
	void shellSort(std::vector<dataType>& dataArr)
	{
		int i, gap, n = dataArr.size();

		for (gap = n / 2; gap > 0; gap = gap / 2) 
		{
			if ((gap % 2) == 0)
			{
				gap++; // gap�� Ȧ���� �����.
			}

			// �κ� ����Ʈ�� ������ gap�� ����.
			for (i = 0; i < gap; i++) 
			{
				// �κ� ����Ʈ�� ���� ���� ���� ����
				insertionSortForGap(dataArr, i, n - 1, gap);
			}
		}
	}

	
}