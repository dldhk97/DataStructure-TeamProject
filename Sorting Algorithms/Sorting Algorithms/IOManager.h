#pragma once
#include <iostream>
#include <string>

enum Menu{INSERT = 1, SORT, DISPLAY, EXIT};

class IOManager
{
public:
	//Getter
	int getMenu();

	void displayMessage(std::string message);
};

