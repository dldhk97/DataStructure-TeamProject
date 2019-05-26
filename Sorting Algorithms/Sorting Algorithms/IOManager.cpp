#include "IOManager.h"

int IOManager::getMenu()
{
	int userInput;
	
	while (1)
	{
		std::cout << "=====================" << "\n";
		std::cout << "1. ������ ���� ����" << "\n";
		std::cout << "2. ����" << "\n";
		std::cout << "3. ���" << "\n";
		std::cout << "4. ����" << "\n";
		std::cout << "=====================" << "\n";
		userInput = getInt("�Է� :");

		if (INSERT <= userInput && userInput <= EXIT)
			return userInput;
		std::cout << "�Է��� �߸��Ǿ����ϴ�." << "\n";
	}
}

int IOManager::getSortType()
{
	int userInput;
	
	while (1)
	{
	std::cout << "=====================" << "\n";
	std::cout << "���� ����" << "\n";
	std::cout << "1. ���� ����" << "\n";
	std::cout << "2. ���� ����" << "\n";
	std::cout << "3. ���� ����" << "\n";
	std::cout << "4. �� ����" << "\n";
	std::cout << "=====================" << "\n";
	userInput = getInt("�Է� :");
	
	if (BUBBLE <= userInput && userInput <= MERGE)
		return userInput;
	std::cout << "�Է��� �߸��Ǿ����ϴ�." << "\n";
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