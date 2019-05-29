#pragma once
#include "Sort.h"
namespace sorts
{
	// 시작 인덱스 first 부터 시작하는 부분리스트를 구성해 삽입 정렬을 시행한다.
	template <typename dataType>
	void insertionSortForGap(std::vector<dataType>& dataArr, int first, int last, int gap)
	{
		int i, j;

		dataType key;

		for (i = first + gap; i <= last; i = i + gap)
		{
			key = dataArr[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

			// 현재 정렬된 배열은 i-gap까지이므로 i-gap번째부터 역순으로 조사한다.
			// j 값은 first 이상이어야 하고
			// key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+gap번째로 이동
			for (j = i - gap; j >= first && dataArr[j] > key; j = j - gap)
			{
				dataArr[j + gap] = dataArr[j]; // 레코드를 gap만큼 오른쪽으로 이동
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
				gap++; // gap을 홀수로 만든다.
			}

			// 부분 리스트의 개수는 gap과 같다.
			for (i = 0; i < gap; i++) 
			{
				// 부분 리스트에 대한 삽입 정렬 수행
				insertionSortForGap(dataArr, i, n - 1, gap);
			}
		}
	}

	
}