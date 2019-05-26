#include "SortManager.h"

void SortManager::insertRandom(std::vector<Rectangle>& recArr)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < dataCapacity; i++)
	{
		recArr.push_back(Rectangle(rand() % 100, rand() % 100));
	}
}