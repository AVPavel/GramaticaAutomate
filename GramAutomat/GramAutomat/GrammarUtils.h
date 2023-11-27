#pragma once
#include "Production.h"
/// <summary>
/// Adaugati orice functie aveti nevoie in plus pentru cele din Grammar
/// </summary>
class GrammarUtils
{
public:
	static bool IsWordGenerated(const std::string& cuvant, const std::vector<std::string>& neterminale);
	static std::vector<int> FindPossibleProductions(const std::string& cuvant, Production productii);
	static void ApplyProduction(std::string cuvant, const Production& productii, const int& index);
};
