#pragma once
#include "Sort.h"
namespace sorts
{
	template <typename dataType>
	void shellSort(std::vector<dataType>& dataArr) // n = size
	{
		// gap과 내부 반복을 위한 j를 변수로 선언
		int gap, j;
		// 초기 gap 값은 배열의 크기 n을 8로 나눈 값을 사용하며
		// 각 단계 별로 2를 나눠간다.
		for (gap = sizeof(dataArr) / 8; gap > 0; gap /= 2)
		{
			// 짝수일 경우 1을 더해주는 것이 성능에 더 도움이 된다.
			if (gap % 2 == 0)
				gap++;

			// j는 각 부분리스트의 시작인덱스 값이다.
			// j가 gap 이전까지만 가는 건 시작 인덱스 값과 gap 값만 알면
			// 배열의 끝까지 갈 수 있기 때문으로 실제 그 과정을
			// 표를 보고 그림을 그려가며 살펴보면 쉽게 알 수 있다.
			for (j = 0; j < gap; j++)
				sorts::insertionSortForGap(dataArr, j, sizeof(dataArr) - 1, gap);
		}
	}

	// 시작 인덱스 first 부터 시작하는 부분리스트를 구성해 삽입 정렬을 시행한다.
	template <typename dataType>
	void insertionSortForGap(std::vector<dataType>& dataArr, int first, int last, int gap)
	{
		dataType key;
		int i, j;

		// 삽입 정렬에서도 첫 번째 원소는 정렬을 할 필요가 없으므로
		// 그 다음 인덱스 값을 key값으로 설정해줬기 때문에 초기값은
		// first + gap이다.
		for (i = first + gap; i <= last; i += gap)
		{
			// 각 반복별로 인덱스 i값에 gap을 더해줌으로써 부분 리스트 삽입 정렬을 구현
			key = dataArr[i];

			// 키 값 이전의 배열의 값들을 조사하면서 key값이 들어갈 위치를 찾는다.
			for (j = i - gap; j >= first && dataArr[j] > key; j -= gap)
			{
				// 마찬가지로 각 반복별로 1을 감소시키는 것이 아닌 gap을 감소시킴으로써
				// 부분리스트의 삽입 정렬을 구현한다.
				dataArr[j + gap] = dataArr[j];
			}
			dataArr[j + gap] = key;
		}
	}
}