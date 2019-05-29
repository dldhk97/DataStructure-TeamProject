#pragma once
#include <iterator>
#include <algorithm>

namespace sorts
{
	//template<typename dataType>		//���� ��������
	//void selectionSort(dataType& dataArr)
	//{
	//	int indexMin, size = dataArr.size();

	//	for (int i = 0; i < size - 1; i++)
	//	{
	//		indexMin = i;
	//		for (int j = i + 1; j < size; j++)
	//		{
	//			if (dataArr[j] < dataArr[indexMin])
	//			{
	//				indexMin = j;
	//			}
	//		}
	//		std::swap(dataArr[indexMin], dataArr[i]);
	//	}
	//}

	// 2019.05.30 00:08 by son : Debug Ÿ������ ���� ��� �� �ڵ�� ���ɻ� ���� ����
	template<typename dataType>		//�ּ��� ��������
	void selectionSort(dataType& dataArr)
	{
		auto begin_iter = std::begin(dataArr);
		auto end_iter = std::end(dataArr);
		auto min_iter = std::begin(dataArr);

		do {
			min_iter = std::min_element(begin_iter, end_iter);
			std::swap(*min_iter, *begin_iter);
			++begin_iter;
		} while (begin_iter != end_iter);
	}
}