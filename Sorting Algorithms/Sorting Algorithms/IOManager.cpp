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
		std::cout << "1. ���� ����(��)" << "\n";
		std::cout << "2. ���� ����(��)" << "\n";
		std::cout << "3. ���� ����(��)" << "\n";
		std::cout << "4. ���� ����(Linked List)" << "\n";
		std::cout << "5. ���� ����(���)(��)" << "\n";
		std::cout << "6. ���� ����(�� ���)" << "\n";
		std::cout << "7. �ڿ� ���� ����" << "\n";
		std::cout << "8. �� ����(��)" << "\n";
		std::cout << "9. �� ����(��)" << "\n";
		std::cout << "10. ��� �� ����(������ ù��° �ǹ�)" << "\n";
		std::cout << "11. ��� �� ����(Median of Three)" << "\n";
		std::cout << "12. ����� �� ����" << "\n";
		std::cout << "13. ��� ����" << "\n";
		std::cout << "14. �⺻ ���� ����(std::sort)" << "\n";
		std::cout << "=====================" << "\n";
		userInput = getInt("�Է� :");

		if (BUBBLE <= userInput && userInput <= STANDARD)
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