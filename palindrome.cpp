#include <iostream>
#include <string>
#include <algorithm>

bool estPalindrome(std::string chaine)
{
    chaine.erase(remove(chaine.begin(), chaine.end(), ' '), chaine.end());
    std::transform(chaine.begin(), chaine.end(), chaine.begin(), ::tolower);

    int debut = 0;
    int fin = chaine.length() - 1;

    while (debut < fin)
    {
        if (chaine[debut] != chaine[fin])
        {
            return false;
        }
        debut++;
        fin--;
    }

    return true;
}

int main()
{
    std::string chaine;
    std::cout << "Entrez une chaine de caracteres: ";
    std::getline(std::cin, chaine);

    if (estPalindrome(chaine))
    {
        std::cout << "La chaine est un palindrome . \n";
    }
    else
    {
        std::cout << "La chaine n'est pas un palindrome. \n";
    }

    return 0;
}