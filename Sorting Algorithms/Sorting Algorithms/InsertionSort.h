#pragma once
#include <iterator>
#include <list>

namespace sorts
{
	// list�� ��� std::upper_bound(���� Ž��)���� �ܼ� ��ȸ�� �� ������
	// ���� ��� �� 2�� ����
	// ��Ƽ�� ��Ʈ��, int�� 100000�� ���� ����
	// ������������������  vector	list
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

	// ���� ��ũ : https://en.cppreference.com/w/cpp/algorithm/rotate
	template<typename Container>
	void insertionSort(Container& container)
	{
		auto first = std::begin(container);
		auto last = std::end(container);

		// std::upper_bound : ������ iterator�� ��ȸ�ϸ鼭 *it���� �Ѿ�� ������ Ž����. �׸��� �� ��ġ(iterator) ��ȯ. stable��
		//					  random iterator�� ��� ���� Ž�� O(log n) �ϰ� �ƴϸ� ���� Ž�� O(N)
		// std::rotate : ���ҵ��� (��������) shift �ϰ� ���� �Ѿ �ֵ��� ������ ������ ����

		// ó��~ó�� ���� ó��~�� ���� ������ ����
		// ó��~it �� �������� *it���� ū �� ã���� �� ��ġ U���� it������ ���� U���� U+1 ���� ������ rotate 
		for (auto it = first; it != last; ++it)
			std::rotate(std::upper_bound(first, it, *it), it, std::next(it));
	}
}