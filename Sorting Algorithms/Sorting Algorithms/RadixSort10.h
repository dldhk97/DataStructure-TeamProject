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
		int* tmpBuffer = new int[n];
		while (maxNumber / exp > 0)
		{
			int decimalBucket[10] = { 0 };
			for (i = 0; i < n; i++)
				decimalBucket[a[i] / exp % 10]++;
			for (i = 1; i < 10; i++)
				decimalBucket[i] += decimalBucket[i - 1];
			for (i = n - 1; i >= 0; i--)
				tmpBuffer[--decimalBucket[a[i] / exp % 10]] = a[i];
			for (i = 0; i < n; i++)
				a[i] = tmpBuffer[i];

			exp *= 10;
		}
	}

}