#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <vector>

class IOManager
{
public:
	template<typename T> void FileReader(std::string file_path, std::vector<T>& result);
	template<typename T> void FileReader(std::string file_path, std::vector<T>& result, std::function<T(std::string)> fn);
};

template<typename T>
inline void IOManager::FileReader(std::string file_path, std::vector<T>& result)
{
	std::ifstream stringReader(file_path);
	std::string readed;
	while (!stringReader.eof())
	{
		std::getline(stringReader, readed, '\n');
		if (readed != "")
		{
			result.push_back(T(readed));
		}
	}
}

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
			//else
			//	result.push_back(T(readed));
		}
	}
}