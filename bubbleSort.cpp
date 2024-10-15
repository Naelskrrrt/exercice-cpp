#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &tableau)
{
    int n = tableau.size();
    bool echange;

    do
    {
        echange = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (tableau[i] > tableau[i + 1])
            {
                std::swap(tableau[i], tableau[i + 1]);
                echange = true;
            }
        }

        n--;
    } while (echange);
}

int main()
{
    std::vector<int> tableau = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Tableau avant le tri : ";
    for (int val : tableau)
    {
        std::cout << val << " ";
    }

    std::cout << std::endl;

    bubbleSort(tableau);

    std::cout << "Tableau après le tri : ";
    for (int val : tableau)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}