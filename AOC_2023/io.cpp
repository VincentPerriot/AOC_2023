#include "io.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

std::string aoc2023::io::ReadToString(const std::string& filename) {
    std::ifstream filestream(filename);
    std::string content;

    if (filestream.is_open()) 
    {
        filestream.ignore(3);
        content.assign((std::istreambuf_iterator<char>(filestream)),
            std::istreambuf_iterator<char>());
        filestream.close();
    }
    else 
    {
        std::cerr << "Error opening file: " << filename << std::endl;
    }

    return content;
}

std::vector<std::string> aoc2023::io::ReadToVecString(const std::string& filename)
{
    std::ifstream filestream(filename);
    std::vector<std::string> content;
    std::string line;

    if (filestream.is_open())
    {
        filestream.ignore(3);
        while (std::getline( filestream, line))
        {
            content.emplace_back(std::move(line));
        }
        filestream.close();
    }
    else
    {
        std::cerr << "Error opening file: " << filename << std::endl;
    }

    return content;
}

std::vector<int> aoc2023::io::ParseIntWhiteSpace(const std::string& str)
{
    std::istringstream stringstream(str);
    std::vector<int> content;
    int num;

    while (stringstream >> num)
    {
        content.emplace_back(num);
    }

    return content;
}

std::vector<std::string> aoc2023::io::ParseStrWhiteSpace(const std::string& str)
{
    std::istringstream stringstream(str);
    std::vector<std::string> content;
    std::string new_str;

    while (stringstream >> new_str)
    {
        content.emplace_back(new_str);
    }

    return content;
}

void aoc2023::io::trimNonNumeric(std::string& str)
{
    str.erase(
        std::remove_if(str.begin(), str.end(), 
            [](char c) { return !std::isdigit(c); }),
        str.end()
    );
}





