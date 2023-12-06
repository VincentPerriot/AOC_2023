#pragma once

#include <string>
#include <vector>
#include <filesystem>

namespace aoc2023::io {

	// File Read
	std::string ReadToString(const std::string& filename);
	std::vector<std::string> ReadToVecString(const std::string& filename);

	// String / Line Read
	std::vector<int> ParseIntWhiteSpace(const std::string& str);
	std::vector<std::string> ParseStrWhiteSpace(const std::string& str);

	// Only keeps numerics from a string
	void trimNonNumeric(std::string& str);

} // end namespace
