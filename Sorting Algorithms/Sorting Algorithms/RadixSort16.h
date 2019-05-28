#pragma once
#include "Sort.h"

namespace sorts
{
	void radixSort16(std::vector<int>& input)
	{
		int n = input.size();
		int i;
		int maxNumber = input[0];
		for (i = 1; i < n; i++)
		{
			if (input[i] > maxNumber)
				maxNumber = input[i];
		}
		int exp = 1;
		int* tmpBuffer = new int[n];
		while (maxNumber / exp > 0)
		{
			int decimalBucket[16] = { 0 };
			for (i = 0; i < n; i++)
				decimalBucket[input[i] / exp % 16]++;

			for (i = 1; i < 16; i++)
				decimalBucket[i] += decimalBucket[i - 1];

			for (i = n - 1; i >= 0; i--)
				tmpBuffer[--decimalBucket[input[i] / exp % 16]] = input[i];
			for (i = 0; i < n; i++)
				input[i] = tmpBuffer[i];

			exp *= 16;
		}
	}
}