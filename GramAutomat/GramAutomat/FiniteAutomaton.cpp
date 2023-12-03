#include "FiniteAutomaton.h"

std::ostream& operator<<(std::ostream& out, const FiniteAutomaton& automaton)
{
    out << "M = ({";
    int n = automaton.stari.size();
    for (int i = 0; i < n; i++)
    {
        out << automaton.stari[i];
        if (i != n - 1)
            out << ", ";
    }
    out << "}, {";
    n = automaton.alfabetIntrare.size();
    for (int i = 0; i < n; i++)
    {
        out << automaton.alfabetIntrare[i];
        if (i != n - 1)
            out << ", ";
    }
    out << "}, " << (char)235 << ", " << automaton.stareInitiala << ", {";
    n = automaton.stariFinale.size();
    for (int i = 0; i < n; i++)
    {
        out << automaton.stariFinale[i];
        if (i != n - 1)
            out << ", ";
    }
    out << "})\n";
    for (auto it = automaton.tranzitii.begin(); it != automaton.tranzitii.end(); it++)
    {
        out << (char)235 << "(" << it->first.first << ", " << it->first.second << ") = {";
        int l = it->second.size();
        for (int i = 0; i < l; i++)
        {
            out << it->second[i];
            if (i != l - 1)
                out << ", ";
        }
        out << "}\n";
    }
    return out;
}

std::istream& operator>>(std::istream& in, FiniteAutomaton& automaton)
{
    in >> automaton.stari >> automaton.alfabetIntrare >> automaton.stareInitiala >> automaton.stariFinale;
    while (!in.eof())
    {
        char stare, val;
        std::string rez;
        in >> stare >> val >> rez;
        automaton.tranzitii[{stare, val}] += rez;
    }
    return in;
}

void FiniteAutomaton::SetStari(std::string stari)
{
    this->stari = stari;
}

void FiniteAutomaton::SetAlfabetIntrare(std::string alfabetIntrare)
{
    this->alfabetIntrare = alfabetIntrare;
}

void FiniteAutomaton::SetStareInitiala(char stareInitiala)
{
    this->stareInitiala = stareInitiala;
}

void FiniteAutomaton::SetStariFinale(std::string stariFinale)
{
    this->stariFinale = stariFinale;
}


void FiniteAutomaton::AddTranzitie(std::pair<std::string, std::string> tranzitie)
{
    if (tranzitie.second.size() == 2)
        tranzitii[{tranzitie.first[0], tranzitie.second[0]}] += tranzitie.second[1];
    else if(tranzitie.second != "-")
        tranzitii[{tranzitie.first[0], tranzitie.second[0]}] += "T";
}

bool FiniteAutomaton::VerifyAutomaton()
{
    //Are sau nu stare initiala
    if (stari.find(stareInitiala) == std::string::npos)
        return false;
    
    //Starea finala este gasita in multimea de stari
    if (CheckAllLettersPartOf(stari, stariFinale) == false)
        return false;

    //Trece prin tranzitii
    for (auto it = tranzitii.begin(); it != tranzitii.end(); it++)
    {
        //Nodul din care pleaca tranzitia exista
        if (stari.find(it->first.first) == std::string::npos)
            return false;

        //simbolul cu care pleaca tranzitia exista
        if (alfabetIntrare.find(it->first.second) == std::string::npos)
            return false;

        //Nodul in care pleaca tranzitia exista
        if (CheckAllLettersPartOf(stari, it->second) == false)
            return false;
    }
    return true;
}


//Verifica daca o tranzitie se duce in mai multe noduri
bool FiniteAutomaton::IsDeterministic()
{    
    for (auto it = tranzitii.begin(); it != tranzitii.end(); it++)
    {
        if (it->second.size() > 1)
            return false;
    }
    return true;
}

bool FiniteAutomaton::CheckWord(std::string word)
{
    std::string stareActuala = "";
    stareActuala += stareInitiala;
    int l = word.size();
    for (int i = 0; i < l; i++)
    {
        std::string stareNoua = "";
        int n = stareActuala.size();
        for (int j = 0; j < n; j++)
        {
            if (!tranzitii[{stareActuala[j], word[i]}].empty())
                stareNoua += tranzitii[{stareActuala[j], word[i]}];
            else
            {
                auto it = tranzitii.find({ stareActuala[j], word[i] });
                tranzitii.erase(it);
            }
        }
        if (stareNoua.size() == 0)
            return false;
        stareActuala = stareNoua;
    }
    if (CheckCommonLetter(stareActuala, stariFinale) == false)
        return false;
    return true;
}
