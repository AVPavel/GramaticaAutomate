#include "GrammarUtils.h"

bool GrammarUtils::IsWordGenerated(const std::string& word, const std::vector<std::string>& neterminale)
{
	for (auto const& simbol : neterminale)
	{
		if (word.find(simbol) != std::string::npos)
		{
			return false;
		}
	}
	return true;
}

std::vector<int> GrammarUtils::FindPossibleProductions(const std::string& cuvant, Production productii)
{
	std::vector<int> indexes;
	for (size_t i = 0; i < productii.getNumberOfRules(); i++)
	{
		if (cuvant.find(productii.mRules[i].left) != std::string::npos)
		{
			indexes.push_back(i);
		}
	}

	return indexes;
}

void GrammarUtils::ApplyProduction(std::string cuvant, const Production& productii, const int& index)
{
	size_t pos = cuvant.find(productii.mRules[index].left);
	std::string replacement;

	//concatenez vectorul
	for (const auto& str : productii.mRules[index].right) {
		replacement += str;
	}


	cuvant.replace(pos, productii.mRules[index].left.size(), replacement);
}

