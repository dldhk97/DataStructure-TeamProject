#include "SortManager.h"
#include "IOManager.h"
#include "Sort.h"

int main()
{
	IOManager iom;
	SortManager sm;

	std::vector<int> intArr;
	std::vector<double> doubleArr;
	std::vector<std::string> strArr;
	std::vector<Rectangle> recArr;
	int userInput;

	iom.FileReader<int>("C:\\Users\\������\\source\\repos\\RandomDataCreator\\int - 10000.txt", intArr);
	iom.FileReader<std::string>("C:\\Users\\������\\source\\repos\\RandomDataCreator\\string - 10000.txt", strArr);
	iom.FileReader<Rectangle>("C:\\Users\\������\\source\\repos\\RandomDataCreator\\rectangle - 10000.txt", recArr);

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
	iom.displayMessage("�����մϴ�.");
	return 0;
}