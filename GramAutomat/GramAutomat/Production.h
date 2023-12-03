#pragma once
#include <string>
#include <vector>
struct Rule
{
	std::string left;
	std::vector<std::string> right;

	Rule(const std::string& left, const std::vector<std::string>& right)
		: left(left), right(right) {}
	std::string toString() const {
		std::string fullRight;
		for (const auto& caracter : this->right) {
			fullRight += caracter;
		}
		return fullRight;
	}
};
class Production
{
public:
	//membrii
	std::vector<Rule> mRules;
	size_t size;

	//Constructori
	Production() = default;
	Production(const std::vector<Rule>& rules) : mRules(rules) {}
	Production(const Production& other) = default;

	//eventual de facut o metoda de ReadReguli / AdaugaRegula / getReguli ca sa fie mai curat
	size_t getNumberOfRules();
	void AddRule(const Rule& rule);
};