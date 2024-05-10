#include <iomanip>
#include <iostream>
#include <random>
#include <utility>

// Funkcja sortująca szybka (quicksort).
void quicksort(int *tab, int left, int right)
{
    // Wybór indeksu środkowego elementu jako pivota.
    int pivotIndex = (int)((left + right)/2);
    int pivot = tab[pivotIndex];
    int i = left;
    int j = i;

    // Wyświetlenie informacji o pivocie.
    std::cout << "pivotIndex: " << pivotIndex << " " << "pivot: " << pivot << '\n';
    // Zamiana pivota z ostatnim elementem.
    tab[pivotIndex] = tab[right];

    // Pętla przechodząca przez elementy tablicy.
    while (i < right) 
    {
        // Szukanie elementów mniejszych od pivota.
        if (tab[i] < pivot) 
        {
            // Informacja o aktualnie przeglądanym elemencie i indeksie j.
            std::cout << "Wartosc i " << i << " wartosc j " << j << '\n';
            // Zamiana miejscami elementów i j w tablicy.
            std::cout << "Zamiana " << tab[i] << " " << tab[j]  << '\n';
            std::swap(tab[i], tab[j]);
            j++;
        }
        i++;
    }

    // Zamiana pivota z elementem na pozycji j.
    tab[right] = tab[j];
    tab[j] = pivot;

    // Wywołanie rekurencyjne dla lewej części tablicy.
    if (left < j - 1) 
    {
        std::cout << "-----------------" << '\n';
        std::cout << "Rekursywne sortowanie prawej części" << '\n';
        quicksort(tab, left, j - 1);
    }

    // Wywołanie rekurencyjne dla prawej części tablicy.
    if (j + 1 < right) 
    {
        std::cout << "-----------------" << '\n';
        std::cout << "Rekursywne sortowanie lewej części" << '\n';
        quicksort(tab, j + 1, right);
    }
}

int main()
{
    // Inicjalizacja generatora liczb pseudolosowych.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 100);

    int n = 10; // Rozmiar tablicy.
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
