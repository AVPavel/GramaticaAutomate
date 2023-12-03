#include "StringCompare.h"

bool StringCompare::CheckCommonLetter(std::string s1, std::string s2)
{
    std::map<char, int> letters;
    int l = s1.size();
    for (int i = 0; i < l; i++)
        letters[s1[i]]++;
    l = s2.size();
    for (int i = 0; i < l; i++)
        if (letters[s2[i]] > 0)
            return true;
    return false;
}

bool StringCompare::CheckAllLettersPartOf(std::string s1, std::string s2)
{
    std::map<char, int> letters;
    int l = s1.size();
    for (int i = 0; i < l; i++)
        letters[s1[i]]++;
    l = s2.size();
    for (int i = 0; i < l; i++)
        if (letters[s2[i]] == 0)
            return false;
    return true;
}