#include <vector>
#include <iostream>
#include "Grammar.h"
#include <fstream>
#include "FiniteAutomaton.h"
void printMenu() 
{
    std::cout <<"----------Meniu----------\n\n";
    std::cout<<"1. Afiseaza Gramatica \n";
    std::cout<<"2. Genereaza n cuvinte\n";    
    std::cout<<"3. Obtine si afiseaza Automatul echivalent\n";
    std::cout<<"4. Verifica cuvant (este sau nu acceptat de automat)\n";
    std::cout << "5. Genereaza cuvant si verifica daca e acceptat de automat\n\n";
    std::cout << "9. Exit\n\n";
    std::cout << "Optiune: ";
}



//FiniteAutomaton transformGrammarInAutomaton(Grammar grammar)
//{
//    FiniteAutomaton automaton;
//    std::vector<std::string> neterminale = grammar.GetNeterminale();
//    neterminale.push_back("T");
//    automaton.SetStari(neterminale); //
//    automaton.SetStareInitiala(grammar.GetSimbolStart());
//    automaton.SetAlfabetIntrare(grammar.GetTerminale()); 
//    if (!grammar.ContainsLambda())
//        automaton.SetStariFinale("T");
//    else
//    {
//        std::string st = "T";
//        st += grammar.GetSimbolStart();
//        automaton.SetStariFinale(st);
//    }
//    std::vector<std::pair<std::string, std::string>> productii = grammar.GetProductii();
//    int n = productii.size();
//    for (int i = 0; i < n; i++)
//        automaton.AddTranzitie(productii[i]);
//    return automaton;
//}

int main()
{
/*  ReadGrammar
    VerifyGrammar
    IsRegular  
*/
    //Daca Gramatica este valida(partea de sus)
    std::cout << "Hello????eee";
    //std::fstream file("GrammarData.txt");
    Grammar* gram = new Grammar();
    //file >> *gram;
    std::fstream file("AutomatonData.txt");
    FiniteAutomaton* automat = new FiniteAutomaton();
    file >> *automat;
    bool OK;
    gram->IsRegular() ? OK = true : OK = false;
    char option;
    if (OK == false)
        std::cout << "Gramatica nu e regulata. Meniu indisponibil.";
    while (OK) {
        printMenu();
        std::cin >> option;
        switch (option) {
        case '1':
            //Afiseaza Gramatica
            std::cout<< *gram;
            break;                
        case '2':
            //Genereaza n cuvinte
            int nrCuvinte;
            std::cout << '\n' << "Numar de cuvinte = ";
            std::cin >> nrCuvinte;
            for (int i = 0; i < nrCuvinte; i++) {
                std::cout << gram->GenerateWord() << '\n';
            }
            break;     
        case '3':
            //Obtine/Afiseaza Automat
            std::cout << "Obtine/Afiseaza automat";
            std::cout << *automat;

            break;
        case '4':
            //Verifica cuvant
            std::cout << "Se verifica un cuvant (din fisier)";
            break;
        case '5':
            //Genereaza cuvant + Verifica
            std::cout << "Se va genera + verifica cuvantul";
            break;
        case '9':
            //Exit
            return EXIT_SUCCESS;
            break;
        default:
            //Optiune invalida
            std::cout << "Optiunea nu se afla in lista";
            break;
        }
        system("pause");
        system("CLS");
    }
}
