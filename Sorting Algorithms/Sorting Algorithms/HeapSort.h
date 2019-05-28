#pragma once
#include "Sort.h"

namespace sorts
{
	int parent(int a)
	{
		return (a - 1) / 2;
	}
	template <typename dataType>
	void heap(std::vector<dataType>& data, int num) {
		for (int i = 1; i < num; i++) {
			int child = i;
			while (child > 0) {
				int root = parent(child);
				if (data[root] < data[child]) {
					dataType temp = data[root];
					data[root] = data[child];
					data[child] = temp;
				}
				child = root;
			}
		}
	}
	template <typename dataType>
	void heapSort(std::vector<dataType>& data)
	{
		int num = data.size();
		heap(data, num); // ���� �����. 

		for (int i = num - 1; i >= 0; i--) {
			// ����ū ����(root)�� �� ������ ���ҿ� ���� 
			dataType temp = data[i];
			data[i] = data[0];
			data[0] = temp;

			// �Ǹ���������(����ū����)�� �����ϰ� �ٽ� ���� �����. 
			heap(data, i);
		}	
		
	}
}
