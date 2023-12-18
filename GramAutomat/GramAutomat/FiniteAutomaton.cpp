#include "FiniteAutomaton.h"

std::ostream& operator<<(std::ostream& out, const FiniteAutomaton& automaton)
{
    // Output set of states
    out << "M = ({";
    for (const auto& state : automaton.stari)
    {
        out << state;
        if (&state != &automaton.stari.back())
            out << ", ";
    }
    out << "},{";

    // Output alphabet
    for (const auto& symbol : automaton.alfabetIntrare)
    {
        out << symbol;
        if (&symbol != &automaton.alfabetIntrare.back())
            out << ", ";
    }

    out << "}, " << (char)235 << ", " << automaton.stareInitiala << ", {";

    // Output set of final states
    for (const auto& finalState : automaton.stariFinale)
    {
        out << finalState;
        if (&finalState != &automaton.stariFinale.back())
            out << ", ";
    }

    out << "})\n";

    // Output transition functions with indices
    int index = 1;
    for (const auto& transition : automaton.tranzitii)
    {
        out << " " << index << "-(" << transition.first.first << ", " << transition.first.second << ")-> " << transition.second << "\n";
        index++;
    }

    return out;
}





std::istream& operator>>(std::istream& in, FiniteAutomaton& automaton)
{
    
    std::string tempStare;
    in >> tempStare;
    automaton.stari.clear();
    for (const auto& character : tempStare) {
        automaton.stari.push_back(std::string(1, character));
    }
    

    
    std::string tempAlfabet;
    in >> tempAlfabet;
    automaton.alfabetIntrare.clear();
    for (const auto& character : tempAlfabet) {
        automaton.alfabetIntrare.push_back(std::string(1, character));
    }
    

    
    in >> automaton.stareInitiala;

    
    std::string tempStareFinala;
    in >> tempStareFinala;
    automaton.stariFinale.clear();
    for (const auto& character : tempStareFinala) {
        automaton.stariFinale.push_back(std::string(1, character));
    }

    
    while (!in.eof())
    {
        char stare, val;
        std::string rez;
        in >> stare >> val >> rez;
        automaton.tranzitii[{stare, val}] += rez;
    }
    return in;
}


void FiniteAutomaton::SetStari(std::vector<std::string> stari)
{
    this->stari = stari;
}

void FiniteAutomaton::SetAlfabetIntrare(std::vector<std::string> alfabetIntrare)
{
    this->alfabetIntrare = alfabetIntrare;
}

void FiniteAutomaton::SetStareInitiala(std::string stareInitiala)
{
    this->stareInitiala = stareInitiala;
}

void FiniteAutomaton::SetStariFinale(std::vector<std::string> stariFinale)
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

//bool FiniteAutomaton::VerifyAutomaton()
//{
//    //Are sau nu stare initiala
//    if (std::find(stari.begin(), stari.end(), stareInitiala) != stari.end())
//        return false;
//
//
//    //Starea finala este gasita in multimea de stari
//    if (std::find(stari.begin(), stari.end(), stariFinale) != stari.end())
//        return false;
//
//    //Trece prin tranzitii
//    for (auto it = tranzitii.begin(); it != tranzitii.end(); it++)
//    {
//        //Nodul din care pleaca tranzitia exista &(A,*)->{B}
//        if (std::find(stari.begin(), stari.end(), it->first.first) != stari.end())
//            return false;
//
//        //simbolul cu care pleaca tranzitia exista
//        if ((std::find(alfabetIntrare.begin(), alfabetIntrare.end(), it->first.second) != alfabetIntrare.end()))
//            return false;
//
//        //Nodul in care pleaca tranzitia exista
//        if (std::find(stari.begin(), stari.end(), it->second) != stari.end())
//            return false;
//    }
//    return true;
//}


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
    int lengthWord = word.size();
    for (int i = 0; i < lengthWord; i++)
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
    for (int i = 0; i < stariFinale.size(); i++) {
        if (CheckCommonLetter(stareActuala, stariFinale[i]) == false)
            return false;
    }
    return true;
}
