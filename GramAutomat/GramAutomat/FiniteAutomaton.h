#pragma once
#include <iostream>
#include <map>
#include <tuple>
#include "Grammar.h"
#include "StringCompare.h"


class FiniteAutomaton : protected StringCompare
{
	std::vector<std::string> stari;
	std::vector<std::string> alfabetIntrare;
	std::string stareInitiala;
	std::vector<std::string> stariFinale;
	std::map<std::pair<char, char>, std::string> tranzitii;
public:
	void SetStari(std::string stari);
	void SetAlfabetIntrare(std::string alfabetIntrare);
	void SetStareInitiala(std::string stareInitiala);
	void SetStariFinale(std::string stariFinale);
	void AddTranzitie(std::pair<std::string, std::string> tranzitie);
	bool VerifyAutomaton();
	bool IsDeterministic();
	bool CheckWord(std::string word);
	friend std::ostream& operator<<(std::ostream& out, const FiniteAutomaton& automaton);
	friend std::istream& operator>>(std::istream& in, FiniteAutomaton& automaton);
};

