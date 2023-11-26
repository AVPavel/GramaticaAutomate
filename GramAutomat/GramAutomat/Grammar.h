#pragma once
#include <vector>
#include <string>
#include "Production.h"
class Grammar
{
	std::vector<std::string> mNeterminale;
	std::vector<std::string> mTerminale;
	std::string mSimbolStart;
	Production productii;
public:
	//Constructori
	Grammar();
	Grammar(const std::vector<std::string>& neterminale, const std::vector<std::string>& terminale, const std::string simbolStart);
	Grammar(const Grammar& grammar);
	~Grammar();

	//Getteri
	std::vector<std::string> GetVariableSymbArray();
	std::vector<std::string> GetFinSymbArray();
	std::string GetStartSymbol();
	Production GetProductions();


	//Metode
	void ReadGrammar(std::fstream& file);
	void PrintGrammar();
	bool VerifyGrammar();
	bool IsRegular();
	std::string GenerateWord();
};