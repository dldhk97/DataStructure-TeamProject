#include "SortManager.h"
#include "Sort.h"

int main()
{
	IOManager iom;
	SortManager sm;
	std::vector<int> dataArr;
	std::vector<Rectangle> recArr;
	int userInput;

	while (1)
	{
		userInput = iom.getMenu();
		if (userInput == EXIT)
			break;
		switch (userInput)
		{
		case INSERT:
			sm.insertRandom(dataArr);
			sm.insertRandom(recArr);
			break;
		case SORT:
			//sorts::bubbleSort(dataArr);
			sorts::insertionSort(dataArr);
			sorts::insertionSort(recArr);
			break;
		case DISPLAY:
			sm.displayArr(dataArr);
			sm.displayArr(recArr);
			break;
		}
	}
	iom.displayMessage("종료합니다.");
	return 0;
}