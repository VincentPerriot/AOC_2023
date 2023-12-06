#include "puzzleUtils.h"
#include <cctype>
#include <map>


int aoc2023::puzzles::findFirstNum(std::string str, std::vector<std::string> patterns)
{
	int res = 0;
	int ref = str.size();

	for (int i = 0; i < patterns.size(); i++)
	{
		int idx = str.find(patterns[i]);
		if (idx != -1 && idx < ref) 
		{
			ref = idx;
			res = i;
		}
	}

	for (int i = 0; i < (ref + 1); i++)
	{
		if (isdigit(str[i]))
		{
			res = str[i] - '0'; 
			break;
		}
	}

	return res;
}
