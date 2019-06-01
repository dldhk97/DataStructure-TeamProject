#pragma once

namespace sorts
{
	// https://www.geeksforgeeks.org/heap-sort/

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
	void heapSort(std::vector<dataType> & arr)
	{
		int count = arr.size() - 1;
		//비감소 순으로 정렬
		//for (int i = count / 2; i >= 1; i--) //히프로 조정
		for (int i = count / 2 - 1; i >= 0; i--)
		{
			//Adjust(arr, i, count);
			heapify(arr, count, i);
		}

		//for (int i = count - 1; i >= 1; i--)
		for (int i = count - 1; i >= 0; i--)
		{
			//std::swap(arr[1], arr[i + 1]);
			std::swap(arr[0], arr[i]);
			//Adjust(arr, 1, i); //히프로 조정
			heapify(arr, i, 0);
		}

		//arr.erase(arr.begin());
	}
}
