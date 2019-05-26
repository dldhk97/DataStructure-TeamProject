#include "IOManager.h"

std::ostream& IOManager::menu(std::ostream& os)
{
	os << "=====================" << "\n";
	os << "1. 데이터 랜덤 삽입" << "\n";
	os << "2. 정렬" << "\n";
	os << "3. 출력" << "\n";
	os << "4. 종료" << "\n";
	os << "=====================" << "\n";

	return os;
}

int IOManager::getMenu()
{
	int userInput;
	
	while (1)
	{
		menu(std::cout);

		std::cin >> userInput;
		if (INSERT <= userInput && userInput <= EXIT)
			return userInput;

		std::cout << "입력이 잘못되었습니다." << "\n";
	}
}

void IOManager::displayMessage(std::string message)
{
	std::cout << message << "\n";
}