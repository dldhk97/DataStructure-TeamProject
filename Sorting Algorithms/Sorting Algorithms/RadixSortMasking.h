#pragma once
#include "Sort.h"

namespace sorts
{
	void radixSortMasking(std::vector<int>& a)
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
			int decimalBucket[16] = { 0 };
			for (i = 0; i < n; i++)
				decimalBucket[a[i] / exp & 15]++;

			for (i = 1; i < 16; i++)
				decimalBucket[i] += decimalBucket[i - 1];
			for (i = n - 1; i >= 0; i--)
				tmpBuffer[--decimalBucket[a[i] / exp & 15]] = a[i];
			for (i = 0; i < n; i++)
				a[i] = tmpBuffer[i];

			exp = exp << 4;
		}
	}

}