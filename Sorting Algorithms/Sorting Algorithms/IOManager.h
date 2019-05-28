#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <vector>

class IOManager
{
public:
	template<typename dataType> void FileReader(std::string file_path, std::vector<dataType>& result);
	template<typename dataType> void FileReader(std::string file_path, std::vector<dataType>& result, std::function<dataType(std::string)> fn);
};

template<typename dataType>
inline void IOManager::FileReader(std::string file_path, std::vector<dataType>& result)
{
	std::ifstream stringReader(file_path);
	std::string readed;
	while (!stringReader.eof())
	{
		std::getline(stringReader, readed, '\n');
		if (readed != "")
		{
			result.push_back(dataType(readed));
		}
	}
}

template<typename dataType>
inline void IOManager::FileReader(std::string file_path, std::vector<dataType>& result, std::function<dataType(std::string)> fn)
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
			//else
			//	result.push_back(T(readed));
		}
	}
}