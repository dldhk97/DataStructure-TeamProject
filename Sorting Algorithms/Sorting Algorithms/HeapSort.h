#pragma once

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
		int count = arr.size() - 1;
		//비감소 순으로 정렬
		for (int i = count / 2; i >= 1; i--) //히프로 조정
		{
			Adjust(arr, i, count);
		}

		for (int i = count - 1; i >= 1; i--)
		{
			std::swap(arr[1], arr[i + 1]);
			Adjust(arr, 1, i); //히프로 조정
		}

		arr.erase(arr.begin());
	}
}
