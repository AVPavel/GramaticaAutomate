#include <vector>
#include <iostream>
#include "Grammar.h"
#include <fstream>
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

int main()
{

/*  ReadGrammar
    VerifyGrammar
    IsRegular  
*/
    //Daca Gramatica este valida(partea de sus)
    std::fstream file("Data.txt");
    Grammar* gram = new Grammar();
    file >> *gram;
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
