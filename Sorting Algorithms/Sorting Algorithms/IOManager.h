#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include "SortManager.h"

enum Menu { INSERT = 1, SORT, DISPLAY, EXIT };

class IOManager
{
public:
	//Get Menu
	int getMenu();
	int getSortType();

	//Getter
	int getInt(std::string message);

	void displayMessage(std::string message);
	template<typename T> void FileReader(std::string file_path, std::vector<T>& result, std::function<T(std::string)> fn = nullptr);
};

template<typename T>
inline void IOManager::FileReader(std::string file_path, std::vector<T>& result, std::function<T(std::string)> fn)
{
	std::ifstream stringReader(file_path);
	std::string readed;
	while (!stringReader.eof())
	{
		std::getline(stringReader, readed, '\n');
		if (readed != "")
		{
			if (fn)
				result.push_back(fn(readed));
			else
				result.push_back(T(readed));
		}
	}
}