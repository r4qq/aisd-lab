#include <iomanip>
#include <iostream>
#include <random>
#include <utility>

void print_array(int* tab, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        std::cout << tab[i];

        if (i < end)
        {
            std::cout << " ";
        }
    }
    std::cout << '\n';
}

// Funkcja sortująca szybka (quicksort).
void quicksort(int *tab, int left, int right)
{
    std::cout << "sprawdzana tablica: ";
    print_array(tab, left, right);


    // Wybór indeksu środkowego elementu jako pivota.
    int pivotIndex = (int)((left + right)/2);
    int pivot = tab[pivotIndex];

    // Wyświetlenie informacji o pivocie.
    std::cout << "pivot: " << pivot << '\n';

    int i = left;
    int j = i;

    // Zamiana pivota z ostatnim elementem.
    tab[pivotIndex] = tab[right];

    // Pętla przechodząca przez elementy tablicy.
    while (i < right) 
    {
        std::cout << "Stan Tablicy ";
        print_array(tab, left, right);
         // Informacja o aktualnie przeglądanym elemencie i indeksie j.
        std::cout << "Wartosc i: " << i << " wartosc j: " << j << '\n';
        
        std::cout << "Czy: " << tab[i] << " < " << pivot << '\n';
        // Szukanie elementów mniejszych od pivota.
        if (tab[i] < pivot) 
        {
            // Zamiana miejscami elementów i j w tablicy.
            std::cout << "Tak, zamiana " << tab[i] << " " << tab[j]  << '\n';
            std::swap(tab[i], tab[j]);
            //Zwiększenie i i j
            std::cout << "Zwieksz i, j" << '\n';
            i++;
            j++;
        }
        else 
        {
            std::cout << "Nie, zwieksz i" << '\n';
            i++;
        }
    }

    // Zamiana pivota z elementem na pozycji j.
    tab[right] = tab[j];
    std::cout << "Zamiana pivota " << "(" << pivot << ")" <<  " na element na pozycji J " << "(" << tab[j] << ")" << '\n';
    tab[j] = pivot;

    std::cout << "Sprawdzana tablica: " << '\n';
    print_array(tab, left, right);

    std::cout << "Czy czesc tablica na lewo od pivota ma wiecej niz 1 element?" << '\n';
    // Wywołanie rekurencyjne dla lewej części tablicy.
    if (left < j - 1) 
    {
        std::cout << "Taj, wykonaj dla lewej" << '\n';
        std::cout << "-----------" << '\n';
        quicksort(tab, left, j - 1);
    }
    else 
    {
        std::cout << "Nie" << '\n';
    }

    std::cout << "Czy czesc tablicy na prawo od pivota ma wiecej niz 1 element?" << '\n';
    // Wywołanie rekurencyjne dla prawej części tablicy.
    if (j + 1 < right) 
    {
        std::cout << "Tak wykonaj dla prawej" << '\n';
        std::cout << "-----------" << '\n';
        quicksort(tab, j + 1, right);
    }
    else 
    {
        std::cout << "Nie" << '\n';
    }
}

int main()
{
    // Inicjalizacja generatora liczb pseudolosowych.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 100);

    int n = 10; // Rozmiar tablicy .
    int tab[n]; // Deklaracja tablicy.

    // Wypełnienie tablicy losowymi liczbami.
    for (int i = 0; i < n; i++)
        tab[i] = distr(gen);

    // Wyświetlenie zawartości tablicy przed sortowaniem.
    std::cout << "Tablica przed sortowaniem:\n";
    for (int i = 0; i < n; i++)
        std::cout << std::setw(4) << tab[i];
    std::cout << '\n';

    // Wywołanie funkcji sortującej.
    quicksort(tab, 0, n-1);

    // Wyświetlenie zawartości tablicy po sortowaniu.
    std::cout << "\nTablica po sortowaniu:\n";
    for (int i = 0; i < n; i++)
        std::cout << std::setw(4) << tab[i];
    std::cout << '\n';

    return 0;
}
