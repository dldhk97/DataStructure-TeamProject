#pragma once
#include <vector>
#include <random>
#include <ctime>
#include "IOManager.h"
#include "Rectangle.h"

enum SortType { BUBBLE = 1, INSERTION, MERGE };

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
	case INSERTION:
		sorts::insertionSort(arr);
		break;
	case MERGE:
		sorts::mergeSort(arr);
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
		std::cout << arr[i] << "\n" ;
}