#pragma once
#include <iostream>
#include <string>
#include <fstream>
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
	template<typename T> void FileReader(std::string file_path, std::vector<T>& result);
	template<> void FileReader(std::string file_path, std::vector<int>& result);
	//void integerFileReader();
	//void stringFileReader();
	//void rectangleFileReader();
};

//void IOManager::integerFileReader()
//{
//	std::vector<int> integerArr;
//	std::string integer;
//	std::ifstream integerReader("integer.txt");
//	while (!integerReader.eof())
//	{
//		std::getline(integerReader, integer, '\n');
//		integerArr.push_back(stoi(integer));
//	}
//}
//
//void IOManager::stringFileReader()
//{
//	std::vector<std::string> stringArr;
//	std::string string;
//	std::ifstream stringReader("string.txt");
//	while (!stringReader.eof())
//	{
//		std::getline(stringReader, string, '\n');
//		stringArr.push_back(string);
//	}
//}
//
//void IOManager::rectangleFileReader()
//{
//	std::vector<Rectangle> rectangleArr;
//	std::string width;
//	std::string height;
//	std::ifstream integerReader("rectangle.txt");
//	while (!integerReader.eof())
//	{
//		std::getline(integerReader, width, ' ');
//		std::getline(integerReader, height, '\n');
//
//		rectangleArr.push_back(Rectangle(stod(width), stod(height)));
//	}
//}

template<typename T>
inline void IOManager::FileReader(std::string file_path, std::vector<T>& result)
{
	std::ifstream stringReader(file_path);
	std::string readed;
	while (!stringReader.eof())
	{
		std::getline(stringReader, readed, '\n');
		if (readed != "")
			result.push_back(T(readed));
	}
}

template<>
inline void IOManager::FileReader(std::string file_path, std::vector<int>& result)
{
	std::ifstream integerReader(file_path);
	std::string readed;
	while (!integerReader.eof())
	{
		std::getline(integerReader, readed, '\n');
		if(readed != "")
			result.push_back(std::stoi(readed));
	}
}
