#pragma once
#include <iostream>
#include <string>
#include "SortManager.h"

enum Menu { INSERT = 1, SORT, DISPLAY, EXIT };

class IOManager
{
	std::ostream& menu(std::ostream&);

public:
	//Get Menu
	int getMenu();
	int getSortType();

	//Getter
	int getInt(std::string message);

	void displayMessage(std::string message);
};

