#pragma once
#include "Sort.h"

namespace sorts
{
	template <typename dataType>
	void Adjust(std::vector<dataType>& arr, const int root, const int num)
	{
		dataType e = arr[root];
		int j = 0;
		for (j = 2 * root; j <= num; j *= 2)
		{
			if (j < num && arr[j] < arr[j + 1])
			{
				j++;
			}
			if (e >= arr[j])
				break;
			arr[j / 2] = arr[j];
		}
		arr[j / 2] = e;
	}

	template <typename dataType>
	void heapSort(std::vector<dataType>& arr)
	{
		std::vector<dataType> arr2;
		int count = arr.size();

		arr2.push_back(arr[0]);
		for (int i = 0; i < count; i++)
			arr2.push_back(arr[i]);

		//�񰨼� ������ ����
		for (int i = count / 2; i >= 1; i--) //������ ����
		{
			Adjust(arr2, i, count);
		}

		for (int i = count - 1; i >= 1; i--)
		{
			std::swap(arr2[1], arr2[i + 1]);
			Adjust(arr2, 1, i); //������ ����
		}

		arr2.erase(arr2.begin());
		arr = arr2;
	}
	//int parent(int a)
	//{
	//	return (a - 1) / 2;
	//}
	//template <typename dataType>
	//void heap(std::vector<dataType>& data, int num) {
	//	for (int i = 1; i < num; i++) {
	//		int child = i;
	//		while (child > 0) {
	//			int root = parent(child);
	//			if (data[root] < data[child]) {
	//				dataType temp = data[root];
	//				data[root] = data[child];
	//				data[child] = temp;
	//			}
	//			child = root;
	//		}
	//	}
	//}
	//template <typename dataType>
	//void heapSort(std::vector<dataType>& data)
	//{
	//	int num = data.size();
	//	heap(data, num); // ���� �����. 

	//	for (int i = num - 1; i >= 0; i--) {
	//		// ����ū ����(root)�� �� ������ ���ҿ� ���� 
	//		dataType temp = data[i];
	//		data[i] = data[0];
	//		data[0] = temp;

	//		// �Ǹ���������(����ū����)�� �����ϰ� �ٽ� ���� �����. 
	//		heap(data, i);
	//	}	
	//}
}
