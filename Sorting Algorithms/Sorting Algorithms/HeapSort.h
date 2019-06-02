#pragma once

namespace sorts
{
	// https://www.geeksforgeeks.org/heap-sort/

	// 이 코드가 기존 코드보다 깨끗함
	// 수행 시간은
	// int : old <= new
	// dou : old <= new
	// str : old > new (차이 큼)
	// rec : 둘다 비슷

	// To heapify a subtree rooted with node i which is 
	// an index in arr[]. n is size of heap 
	template <typename dataType>
	void heapify(std::vector<dataType>& arr, int n, int i)
	{
		int largest = i; // Initialize largest as root 
		int l = 2 * i + 1; // left = 2*i + 1 
		int r = 2 * i + 2; // right = 2*i + 2 

		// If left child is larger than root 
		if (l < n && arr[l] > arr[largest])
			largest = l;

		// If right child is larger than largest so far 
		if (r < n && arr[r] > arr[largest])
			largest = r;

		// If largest is not root 
		if (largest != i)
		{
			std::swap(arr[i], arr[largest]);

			// Recursively heapify the affected sub-tree 
			heapify(arr, n, largest);
		}
	}

	template <typename dataType>
	void heapSort(std::vector<dataType> & arr)
	{
		int count = arr.size() - 1;

		for (int i = count / 2 - 1; i >= 0; i--)
		{
			heapify(arr, count, i);
		}

		for (int i = count - 1; i >= 0; i--)
		{
			std::swap(arr[0], arr[i]);
			heapify(arr, i, 0);
		}
	}
}
