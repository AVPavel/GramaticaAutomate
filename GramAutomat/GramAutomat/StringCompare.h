#pragma once

#include <iostream>
#include <map>

class StringCompare
{
protected:
	bool CheckCommonLetter(std::string s1, std::string s2);
	bool CheckAllLettersPartOf(std::string s1, std::string s2);
};

