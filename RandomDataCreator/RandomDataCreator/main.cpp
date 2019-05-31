#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <string>

enum MenuType { MAKENEW = 1, EXIT };
enum DataType { INT = 11, DOUBLE, STRING, RECTANGLE };

//const std::string PATH = "C:\\Users\\Administrator\\source\\repos\\dldhk97\\MyDevelopment\\C++\\RandomDataCreator\\Debug\\";		//절대 경로 사용 시
const std::string PATH = "";																										//기본 경로 사용 시

int getMenu()
{
	int userInput;
	std::cout << "==========" << "\n";
	std::cout << "1. 생성" << "\n";
	std::cout << "2. EXIT" << "\n";
	std::cout << "==========" << "\n";
	std::cin >> userInput;
	if (MAKENEW <= userInput && userInput <= EXIT)
		return userInput;
	std::cout << "입력 오류" << "\n";
}

void writeInt(std::string fileName, int cnt)
{
	std::ofstream os(fileName);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < cnt; i++)
	{
		os << rand() << "\n";
	}

	std::cout << "INT 완료" << "\n";
}

void writeDouble(std::string fileName, int cnt)
{
	std::ofstream os(fileName);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < cnt; i++)
	{
		os << rand() / (float)RAND_MAX * 1.0f << "\n";
	}

	std::cout << "DOUBLE 완료" << "\n";
}

void genRandStr(char* s, const int len)
{
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

	for (int i = 0; i < len; ++i)
	{
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;
}

void writeString(std::string fileName, int cnt)
{
	std::ofstream os(fileName);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < cnt; i++)
	{
		char s[9];
		int length = rand() % 8 + 1;			//문자열의 길이도 난수로 하고 싶으면 rand() % 100으로 대체할 것.
		genRandStr(s, length);

		os << std::string(s) << "\n";
	}
	std::cout << "STRING 완료" << "\n";
}

void writeRectangle(std::string fileName, int cnt)
{
	std::ofstream os(fileName);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < cnt; i++)
	{
		os << rand() % 100 + 1 << " " << rand() % 100 + 1 << "\n";
	}

	std::cout << "RECTANGLE 완료" << "\n";
}


void makeNewFile()
{
	std::string fileName;
	int cnt;
	std::cout << "개수 입력 :";
	std::cin >> cnt;
	fileName = std::to_string(cnt);

	writeInt(PATH + "int - " + fileName + ".txt", cnt);
	writeDouble(PATH + "double - " + fileName + ".txt", cnt);
	writeString(PATH + "string - " + fileName + ".txt", cnt);
	writeRectangle(PATH + "rectangle - " + fileName + ".txt", cnt);
}

int main()
{
	int userInput;

	while (1)
	{
		userInput = getMenu();
		if (userInput == EXIT)
			break;
		switch (userInput)
		{
		case MAKENEW:
			makeNewFile();
			break;
		default:
			std::cout << "ERROR";
			break;
		}
	}
	return 0;
}