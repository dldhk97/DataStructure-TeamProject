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
		std::cout << "�Է� :";
		std::cin >> userInput;
		if (INSERT <= userInput && userInput <= EXIT)
			return userInput;

		std::cout << "�Է��� �߸��Ǿ����ϴ�." << "\n";
	}
}

void IOManager::displayMessage(std::string message)
{
	std::cout << message << "\n";
}