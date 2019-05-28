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
		std::cout << "1. 버블 정렬(완)" << "\n";
		std::cout << "2. 선택 정렬(완)" << "\n";
		std::cout << "3. 삽입 정렬(완)" << "\n";
		std::cout << "4. 삽입 정렬(Linked List)" << "\n";
		std::cout << "5. 병합 정렬(재귀)(손)" << "\n";
		std::cout << "6. 병합 정렬(비 재귀)" << "\n";
		std::cout << "7. 자연 병합 정렬" << "\n";
		std::cout << "8. 쉘 정렬(완)" << "\n";
		std::cout << "9. 힙 정렬(완)" << "\n";
		std::cout << "10. 재귀 퀵 정렬(무조건 첫번째 피벗)" << "\n";
		std::cout << "11. 재귀 퀵 정렬(Median of Three)" << "\n";
		std::cout << "12. 비재귀 퀵 정렬" << "\n";
		std::cout << "13. 기수 정렬" << "\n";
		std::cout << "14. 기본 제공 정렬(std::sort)" << "\n";
		std::cout << "=====================" << "\n";
		userInput = getInt("입력 :");

		if (BUBBLE <= userInput && userInput <= STANDARD)
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