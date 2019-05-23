#pragma once
#include <iostream>
#include <string>

enum Menu{INSERT = 1, SORT, DISPLAY, EXIT};

class IOManager
{
	std::ostream& menu(std::ostream&);

public:
	//Getter
	int getMenu();

	void displayMessage(std::string message);
};

