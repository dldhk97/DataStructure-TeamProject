#pragma once
#include <vector>
#include <random>
#include <ctime>
#include "IOManager.h"
#include "Rectangle.h"

const int dataCapacity = 10;

class SortManager
{
public:
	template <typename dataType>
	void insertRandom(std::vector<dataType>& dataArr);
	void insertRandom(std::vector<std::string>& recArr);
	void insertRandom(std::vector<Rectangle>& recArr);
	
	template <typename dataType>
	void displayArr(std::vector<dataType>& dataArr);

	void genRandStr(char* s, const int len);
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
void SortManager::displayArr(std::vector<dataType>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << "\n" ;
}