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
		heap(data, num); // 힙을 만든다. 

		for (int i = num - 1; i >= 0; i--) {
			// 가장큰 숫자(root)를 맨 마지막 원소와 스왑 
			dataType temp = data[i];
			data[i] = data[0];
			data[0] = temp;

			// 맨마지막원소(가장큰원소)를 제외하고 다시 힙을 만든다. 
			heap(data, i);
		}	
		
	}
}
