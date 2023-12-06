#include "day1.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <numeric>
#include <map>

#include "io.h"
#include "puzzleUtils.h"


void day1::printPart1()
{
	std::vector<std::string> input = aoc2023::io::ReadToVecString("./inputs/input_1.txt");
	std::vector<int> values;

	for (std::string& line : input)
	{
		aoc2023::io::trimNonNumeric(line);
		if (!line.empty())
		{
			int d1 = line[0] - '0';
			int d2 = line[line.size() - 1] - '0';

			values.push_back(10*d1 + d2);
		}
	}

	int res = std::accumulate(values.begin(), values.end(), 0);

	std::cout << res << std::endl;
}

void day1::printPart2()
{
	std::vector<std::string> input = aoc2023::io::ReadToVecString("./inputs/input_1.txt");
	std::vector<int> values;

	std::vector<std::string> patterns{
		"zero",
		"one", 
		"two", 
		"three",
		"four",
		"five",
		"six", 
		"seven",
		"eight",
		"nine"
	};

	std::vector<std::string> revPatterns;
	
	std::for_each(patterns.begin(), patterns.end(),
		[&revPatterns](const std::string& str) {
			std::string rev_str = std::string(str.rbegin(), str.rend());
			revPatterns.push_back(rev_str);
		});

	for (std::string& line : input)
	{
		int d1 = aoc2023::puzzles::findFirstNum(line, patterns);

		std::string revLine(line.rbegin(), line.rend());
		int d2 = aoc2023::puzzles::findFirstNum(revLine, revPatterns);

		std::cout << line << "\n First num = " << d1 << " Second Num = " << d2 << std::endl;

		values.push_back(10 * d1 + d2);
	}

	int res = std::accumulate(values.begin(), values.end(), 0);

	std::cout << res << std::endl;
}
