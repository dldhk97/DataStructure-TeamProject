#include "SortManager.h"


//���ڿ��� �������� �����Ͽ� ����.
void SortManager::insertRandom(std::vector<std::string>& strArr)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < dataCapacity; i++)
	{
		char s[11];
		int length = 10;			//���ڿ��� ���̵� ������ �ϰ� ������ rand() % 100���� ��ü�� ��.
		genRandStr(s, length);
		strArr.push_back(s);
	}
}

void SortManager::insertRandom(std::vector<Rectangle>& recArr)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < dataCapacity; i++)
	{
		recArr.push_back(Rectangle(rand() % 100, rand() % 100));
	}
}

void SortManager::genRandStr(char* s, const int len)
{
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;
}