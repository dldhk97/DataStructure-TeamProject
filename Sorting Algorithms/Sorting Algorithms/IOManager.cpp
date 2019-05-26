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
		std::cout << "=====================" << "\n";
		std::cout << "1. 데이터 랜덤 삽입" << "\n";
		std::cout << "2. 정렬" << "\n";
		std::cout << "3. 출력" << "\n";
		std::cout << "4. 종료" << "\n";
		std::cout << "=====================" << "\n";
		userInput = getInt("입력 :");

		if (INSERT <= userInput && userInput <= EXIT)
			return userInput;
		std::cout << "입력이 잘못되었습니다." << "\n";
	}
}

int IOManager::getSortType()
{
	int userInput;
	
	while (1)
	{
	std::cout << "=====================" << "\n";
	std::cout << "정렬 선택" << "\n";
	std::cout << "1. 버블 정렬" << "\n";
	std::cout << "2. 삽입 정렬" << "\n";
	std::cout << "3. 병합 정렬" << "\n";
	std::cout << "4. 퀵 정렬" << "\n";
	std::cout << "=====================" << "\n";
	userInput = getInt("입력 :");
	
	if (BUBBLE <= userInput && userInput <= MERGE)
		return userInput;
	std::cout << "입력이 잘못되었습니다." << "\n";
	}
}

int IOManager::getInt(std::string message)
{
	int userInput;
	std::cout << message;
	std::cin >> userInput;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10, '\n');
	}
	
	return userInput;
}


void IOManager::displayMessage(std::string message)
{
	std::cout << message << "\n";
}