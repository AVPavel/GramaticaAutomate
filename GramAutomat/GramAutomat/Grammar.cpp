#include "Grammar.h"
#include "GrammarUtils.h"
#include <random>

Grammar::Grammar()
{
	mNeterminale.clear();
	mTerminale.clear();
	mSimbolStart = "";
}

Grammar::Grammar(const std::vector<std::string>& neterminale, const std::vector<std::string>& terminale, const std::string simbolStart, const Production& productii):
	mNeterminale{neterminale}, mTerminale{terminale}, mSimbolStart{simbolStart}, mProductii{productii} {}

Grammar::Grammar(const Grammar& grammar):
	mNeterminale{grammar.mNeterminale}, mTerminale{ grammar.mTerminale }, mSimbolStart{ grammar.mSimbolStart }, mProductii{ grammar.mProductii } {}

std::vector<std::string> Grammar::GetNeterminale()
{
	return mNeterminale;
}

std::vector<std::string> Grammar::GetTerminale()
{
	return mTerminale;
}

std::string Grammar::GetSimbolStart()
{
	return mSimbolStart;
}

Production Grammar::GetProductii()
{
	return mProductii;
}

std::string Grammar::GenerateWord()
{
	size_t contor = 0;
	std::string cuvant = mSimbolStart;
	if (!GrammarUtils::IsWordGenerated(cuvant, mNeterminale))
	{
		++contor;
		std::vector<int> productiiPosibile = GrammarUtils::FindPossibleProductions(cuvant, mProductii);
		
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_int_distribution<> distr(0, productiiPosibile.size() - 1);

		int randomIndex = distr(eng);
		
		GrammarUtils::ApplyProduction(cuvant, mProductii, randomIndex);
		
	}
}

