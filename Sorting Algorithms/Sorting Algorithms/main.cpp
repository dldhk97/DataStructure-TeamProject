#include "SortManager.h"
#include "Sort.h"

int main()
{
	IOManager iom;
	SortManager sm;
	std::vector<int> dataArr;
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
			break;
		case SORT:
			//sorts::bubbleSort(dataArr);
			sorts::insertionSort(dataArr);
			break;
		case DISPLAY:
			sm.displayDataArr(dataArr);
			break;
		}
	}
	iom.displayMessage("종료합니다.");
	return 0;
}