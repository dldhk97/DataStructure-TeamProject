#include "SortManager.h"
#include "Sort.h"

int main()
{
	IOManager iom;
	SortManager sm;

	std::vector<int> intArr;
	std::vector<std::string> strArr;
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
			sm.insertRandom(intArr);
			sm.insertRandom(strArr);
			sm.insertRandom(recArr);
			break;
		case SORT:
			userInput = iom.getSortType();
			sm.sort(userInput, intArr);
			sm.sort(userInput, strArr);
			sm.sort(userInput, recArr);
			break;
		case DISPLAY:
			sm.displayArr(intArr);
			sm.displayArr(strArr);
			sm.displayArr(recArr);
			break;
		}
	}
	iom.displayMessage("종료합니다.");
	return 0;
}