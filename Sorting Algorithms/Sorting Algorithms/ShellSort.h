#pragma once
#include "Sort.h"
namespace sorts
{
	template <typename dataType>
	void shellSort(std::vector<dataType>& dataArr) // n = size
	{
		// gap�� ���� �ݺ��� ���� j�� ������ ����
		int gap, j;
		// �ʱ� gap ���� �迭�� ũ�� n�� 8�� ���� ���� ����ϸ�
		// �� �ܰ� ���� 2�� ��������.
		for (gap = sizeof(dataArr) / 8; gap > 0; gap /= 2)
		{
			// ¦���� ��� 1�� �����ִ� ���� ���ɿ� �� ������ �ȴ�.
			if (gap % 2 == 0)
				gap++;

			// j�� �� �κи���Ʈ�� �����ε��� ���̴�.
			// j�� gap ���������� ���� �� ���� �ε��� ���� gap ���� �˸�
			// �迭�� ������ �� �� �ֱ� �������� ���� �� ������
			// ǥ�� ���� �׸��� �׷����� ���캸�� ���� �� �� �ִ�.
			for (j = 0; j < gap; j++)
				sorts::insertionSortForGap(dataArr, j, sizeof(dataArr) - 1, gap);
		}
	}

	// ���� �ε��� first ���� �����ϴ� �κи���Ʈ�� ������ ���� ������ �����Ѵ�.
	template <typename dataType>
	void insertionSortForGap(std::vector<dataType>& dataArr, int first, int last, int gap)
	{
		dataType key;
		int i, j;

		// ���� ���Ŀ����� ù ��° ���Ҵ� ������ �� �ʿ䰡 �����Ƿ�
		// �� ���� �ε��� ���� key������ ��������� ������ �ʱⰪ��
		// first + gap�̴�.
		for (i = first + gap; i <= last; i += gap)
		{
			// �� �ݺ����� �ε��� i���� gap�� ���������ν� �κ� ����Ʈ ���� ������ ����
			key = dataArr[i];

			// Ű �� ������ �迭�� ������ �����ϸ鼭 key���� �� ��ġ�� ã�´�.
			for (j = i - gap; j >= first && dataArr[j] > key; j -= gap)
			{
				// ���������� �� �ݺ����� 1�� ���ҽ�Ű�� ���� �ƴ� gap�� ���ҽ�Ŵ���ν�
				// �κи���Ʈ�� ���� ������ �����Ѵ�.
				dataArr[j + gap] = dataArr[j];
			}
			dataArr[j + gap] = key;
		}
	}
}