#include "IOManager.h"

std::ostream& IOManager::menu(std::ostream& os)
{
	os << "=====================" << "\n";
	os << "1. ������ ���� ����" << "\n";
	os << "2. ����" << "\n";
	os << "3. ���" << "\n";
	os << "4. ����" << "\n";
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

		std::cout << "�Է��� �߸��Ǿ����ϴ�." << "\n";
	}
}

void IOManager::displayMessage(std::string message)
{
	std::cout << message << "\n";
}