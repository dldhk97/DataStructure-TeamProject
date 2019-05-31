#pragma once
#include "Sort.h"

namespace sorts
{
	void radixSort10(std::vector<int>& a)
	{
		int n = a.size();
		int i;
		int maxNumber = a[0];
		for (i = 1; i < n; i++)
		{
			if (a[i] > maxNumber)
				maxNumber = a[i];
		}
		int exp = 1;
		int* tempBuffer = new int[n];
		while (maxNumber / exp > 0)
		{
			int Bucket[10] = { 0 };
			for (i = 0; i < n; i++)
				Bucket[a[i] / exp % 10]++;
			for (i = 1; i < 10; i++)
				Bucket[i] += Bucket[i - 1];
			for (i = n - 1; i >= 0; i--)
				tempBuffer[--Bucket[a[i] / exp % 10]] = a[i];
			for (i = 0; i < n; i++)
				a[i] = tempBuffer[i];

			exp *= 10;
			if (exp == 0)
				break;
		}
	}

}