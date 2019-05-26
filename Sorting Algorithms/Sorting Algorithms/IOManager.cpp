#include "IOManager.h"

int IOManager::getMenu()
{
	int userInput;
	
	while (1)
	{
		std::cout << "=====================" << "\n";
		std::cout << "1. 데이터 랜덤 삽입" << "\n";
		std::cout << "2. 정렬" << "\n";
		std::cout << "3. 출력" << "\n";
		std::cout << "4. 종료" << "\n";
		std::cout << "=====================" << "\n";
		std::cout << "입력 :";
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