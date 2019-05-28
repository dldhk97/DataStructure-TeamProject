#pragma once
#include <vector>
#include <random>
#include <ctime>
#include "IOManager.h"
#include "Rectangle.h"

enum SortType { BUBBLE = 1, SELECTION, INSERTION, INSERTION_LIST, MERGE_RECURSIVE, MERGE_NON_RECURSIVE, MERGE_NATURAL, SHELL, HEAP, QUICK_RECURSIVE_FIRST, QUICK_RECURSIVE_MEDIAN, QUICK_NON_RECURSIVE, RADIX, STANDARD };

const int dataCapacity = 10;

class SortManager
{
public:
	template <typename dataType>
	void sort(int sortType, std::vector<dataType>& arr);

	template <typename dataType>
	void insertRandom(std::vector<dataType>& arr);
	void insertRandom(std::vector<std::string>& recArr);
	void insertRandom(std::vector<Rectangle>& recArr);

	template <typename dataType>
	void displayArr(std::vector<dataType>& arr);

	void genRandStr(char* s, const int len);
};

template <typename dataType>
void SortManager::sort(int sortType, std::vector<dataType>& arr)
{
	switch (sortType)
	{
	case BUBBLE:
		sorts::bubbleSort(arr);
		break;
	case SELECTION:
		sorts::insertionSort(arr);
		break;
	case INSERTION:
		sorts::mergeSort(arr);
		break;
	case INSERTION_LIST:
		sorts::shellSort(arr);
		break;
	case MERGE_RECURSIVE:
		sorts::heapSort(arr);
		break;
	case MERGE_NON_RECURSIVE:
		break;
	case MERGE_NATURAL:
		break;
	case SHELL:
		break;
	case HEAP:
		break;
	case QUICK_RECURSIVE_FIRST:
		break;
	case QUICK_RECURSIVE_MEDIAN:
		break;
	case QUICK_NON_RECURSIVE:
		break;
	case RADIX:
		break;
	case STANDARD:
		break;
	default:
		//debug
		std::cout << "INVALID SORT TYPE\n";
		break;
	}
}

template <typename dataType>
void SortManager::insertRandom(std::vector<dataType>& arr)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < dataCapacity; i++)
	{
		arr.push_back(rand() % 100);
	}
}

template <typename dataType>
void SortManager::displayArr(std::vector<dataType>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << "\n";
}