#pragma once
#include <vector>
#include <random>
#include <ctime>
#include "IOManager.h"

const int dataCapacity = 10;

class SortManager
{
public:
	template <typename dataType>
	void insertRandom(std::vector<dataType>& dataArr);

	template <typename dataType>
	void displayDataArr(std::vector<dataType>& dataArr);
};

template <typename dataType>
void SortManager::insertRandom(std::vector<dataType>& dataArr)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < dataCapacity; i++)
	{
		dataArr.push_back(rand() % 100);
	}
}

template <typename dataType>
void SortManager::displayDataArr(std::vector<dataType>& dataArr)
{
	IOManager iom;
	for (int i = 0; i < dataArr.size(); i++)
		iom.displayMessage(std::to_string(dataArr[i]));
}