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
	return "";
}

bool Grammar::VerifyGrammar() {
	//din curs
	//VN -> neterminale alfabet finit nevid
	//VT -> terminale alfabtet finit nevid si Vt intersectat cu VN != multimea vida
	// S apartine lui VN -> simbol de start
	// 	P = o multime finit a de perechi ordonate (u, v ), u, v ∈ (VN ⋃ VT )∗ si u contine
	// cel putin un element din VN . Elementele lui P se numesc productii si se
	// noteaza u → v
	if (mNeterminale.empty()) {
		return false;
	}
	if (mTerminale.empty()) {
		return false;
	}
	//sa nu aiba elemente comune terminalele cu neterminalele
	for (const auto& terminal : mTerminale) {
		if (std::find(mNeterminale.begin(), mNeterminale.end(), terminal) != mNeterminale.end()) {
			return false;
		}
	}
	//simbolul de start trebuie sa fie un neterminal
	if (std::find(mNeterminale.begin(), mNeterminale.end(), mSimbolStart) == mNeterminale.end()) {
		return false;
	}

	//aici se verifica daca fiecare caracter din u si fiecare caracter din v apartin ori lui mTerminal ori mNeterminal
	//si daca u are cel putin un singur caracter din mNeterminal
	for (const auto& [u, v] : mProductii.mRules) {

	}


}

bool Grammar::IsRegular() {
	//ar trb sa fie de forma asta
	// A -> aB sau A-> a
	// si A ,B sunt neterminale si a e terminal
	//deci practic in stanga sa fie mereu doar un caracter si in dreapta ori sa fie doar terminal
	//ori sa fie terminal si neterminal in ordinea asta
	for (const auto& [u, v] : this->mProductii.mRules) {
		if (u.size() > 1) {
			return false;
		}
		if (v.size() > 2) {
			return false;
		}
		if (GrammarUtils::IsNeterminal(u, this->mNeterminale) == false) {
			return false;
		}
		if (GrammarUtils::IsTerminal(v[0], this->mTerminale) == false) {
			return false;
		}
		if (v.size() == 2) {
			if (GrammarUtils::IsNeterminal(v[1], this->mNeterminale) == false) {
				return false;
			}
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& out, const Grammar& grammar)
{
	out << "G = ({";
	int n = grammar.mNeterminale.size();
	for (int i = 0; i < n; i++)
	{
		out << grammar.mNeterminale[i];
		if (i != n - 1)
			out << ", ";
	}
	out << "}, {";
	n = grammar.mTerminale.size();
	for (int i = 0; i < n; i++)
	{
		out << grammar.mTerminale[i];
		if (i != n - 1)
			out << ", ";
	}
	out << "}, " << grammar.mSimbolStart << ", P)";
	out << "\nP: ";
	int i = 1;
	for (const auto& rule : grammar.mProductii.mRules)
		out << i++ << ") " << rule.left << " -> ";// << rule.right << '\n';
	return out;
}


std::istream& operator>>(std::istream& in, Grammar& g)
{
	// Read individual elements of mNeterminale, mTerminale, and mSimbolStart
	in >> g.mNeterminale >> g.mTerminale >> g.mSimbolStart;

	// Clear any existing rules in mProductii before reading new ones
	g.mProductii.mRules.clear();

	while (true) {
		std::string word, derivedWord;
		in >> word >> derivedWord;

		// Check for the end of the input
		if (in.eof())
			break;

		// Assuming mProductii is a Production object
		Rule rule(word, { derivedWord });
		g.mProductii.AddRule(rule);
	}

	return in;
}

