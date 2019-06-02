#pragma once
#include <iterator>
#include <list>

namespace sorts
{
	// list의 경우 std::upper_bound(이진 탐색)보다 단순 순회가 더 빠르다
	// 실험 결과 약 2배 차이
	// 펜티엄 노트북, int형 100000개 정렬 기준
	// 　　　　　　　　　  vector	list
	// std::upper_bound     4		88796
	// sorts::upper_bound   4708		43053
	template<class ForwardIt, class T>
	ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value)
	{
		auto it = first;
		while (it != last)
		{
			if (value < *it)
				return it;

			++it;
		}
		return it;
	}

	// 참고 링크 : https://en.cppreference.com/w/cpp/algorithm/rotate
	template<typename Container>
	void insertionSort(Container& container)
	{
		auto first = std::begin(container);
		auto last = std::end(container);

		// std::upper_bound : 지정한 iterator를 순회하면서 *it값을 넘어가는 지점을 탐색함. 그리고 그 위치(iterator) 반환. stable함
		//					  random iterator의 경우 이진 탐색 O(log n) 하고 아니면 순차 탐색 O(N)
		// std::rotate : 원소들을 (왼쪽으로) shift 하고 왼쪽 넘어간 애들은 오른쪽 끝으로 넣음

		// 처음~처음 부터 처음~끝 까지 루프를 돈다
		// 처음~it 안 루프에서 *it보다 큰 값 찾으면 그 위치 U부터 it까지의 값을 U부터 U+1 범위 내에서 rotate 
		for (auto it = first; it != last; ++it)
			std::rotate(std::upper_bound(first, it, *it), it, std::next(it));
	}
}