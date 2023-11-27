#pragma once
#include <vector>
#include <string>
#include "Production.h"
class Grammar
{
	std::vector<std::string> mNeterminale;
	std::vector<std::string> mTerminale;
	std::string mSimbolStart;
	Production mProductii;
public:
	//Constructori
	Grammar();
	Grammar(const std::vector<std::string>& neterminale, const std::vector<std::string>& terminale, const std::string simbolStart, const Production& productii);
	Grammar(const Grammar& grammar);
	~Grammar() = default;

	//Getteri
	std::vector<std::string> GetNeterminale();
	std::vector<std::string> GetTerminale();
	std::string GetSimbolStart();
	Production GetProductii();


	//Metode
	void ReadGrammar(std::fstream& file);
	void PrintGrammar();
	bool VerifyGrammar();
	bool IsRegular();
	std::string GenerateWord();
};