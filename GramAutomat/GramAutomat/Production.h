#pragma once
#include <string>
#include <vector>
struct Rule
{
	std::string left;
	std::vector<std::string> right;

	Rule(const std::string& left, const std::vector<std::string>& right);
};
class Production
{
	std::vector<Rule> mRules;

	//Constructori
	Production() = default;
	explicit Production(const std::vector<Rule>& rules) : mRules(rules) {}
	Production(const Production& other) = default;

	//eventual de facut o metoda de ReadReguli / AdaugaRegula / getReguli ca sa fie mai curat
};