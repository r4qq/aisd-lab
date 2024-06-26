//Stanisław Rak 235IC B1
#include <iostream>

int* makeArray(int x)
{
    //tworzenie tablicy dynamicznej o podanym rozmiarze
    int* newArray = new int[x];
    return newArray;
}

void instertToArray(int* array, int arraySize)
{
    int znak;
    //wstawianie liczb podanych przez użytkownika do wcześniej stworzonej tablicy 
    for (int i = 0; i < arraySize; i++) {
        std::cin >> znak;
        array[i] = znak;
    }
}

void showArray(int* array, int start, int stop)
{
    // Pętla wyświetla elementy tablicy od indeksu startowego do indeksu końcowego
    for (int i = start; i <= stop; i++)
    {
        std::cout << array[i] << " "; // Wyświetlanie bierzącego elementu tablicy
    }
    std::cout << '\n'; //Znak nowej linii
}

void bubbleSort(int* array, int arraySize)
{
    int temp; // Zmienna tymczasowa używana do zamiany elementów
    bool sorted; //zmienna sprawdzająca czy dokonano zamiany elemntów

    // Zewnętrzna pętla służąca do przeglądania tablicy
    for (int i = 0; i < arraySize; i++)
    {
        // Wewnętrzna pętla porównuje sąsiadujące elementy i zamienia je, jeśli jest to konieczne
        for (int j = 0; j < arraySize - 1; j++)
        {
            sorted = false;
            //Sprawdzenie czy poprzedni elemnt jest większy niż nastepny element
            if (array[j] > array[j + 1])
            {
                // Zamienia elementy za pomocą zmiennej tymczasowej
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                sorted = true;
            }
            //Wyświetlanie tablicy
            showArray(array, 0, arraySize - 1);
        }
        //sprawdzenie czy dokonano zmiany
        if(!sorted)
        {
            return;
        }
    }
}

void selectionSort(int* array, int arraySize)
{
    // Pętla iteruje przez wszystkie elementy tablicy poza ostatnim
    for (int i = 0; i < arraySize - 1; ++i)
    {
        int minIndex = i; // Ustawia indeks minimalnego elementu na bieżący indeks
        // Pętla znajduje indeks najmniejszego elementu w nieposortowanej części tablicy

        //Wyświetlanie tablicy
        showArray(array, 0, arraySize - 1);

        for (int j = i + 1; j < arraySize; ++j)
        {
            if (array[j] < array[minIndex]) // Sprawdza, czy bieżący element jest mniejszy od minimalnego
                minIndex = j; // Aktualizuje indeks minimalnego elementu
        }
        // Jeśli indeks minimalnego elementu nie jest równy bieżącemu indeksowi, zamienia je miejscami
        if (minIndex != i)
        {
            int temp = array[i]; // Zmienna tymczasowa przechowuje bieżący element
            array[i] = array[minIndex]; // Przypisuje bieżący element na miejsce minimalnego elementu
            array[minIndex] = temp; // Przypisuje minimalny element na miejsce bieżącego elementu
        }

    }
}

void insertSort(int* array, int arraySize)
{
    // Pętla iteruje od przedostatniego elementu do pierwszego
    for (int i = arraySize - 2; i >= 0; i--) {

        //Wyświetlanie tablicy
        showArray(array, 0, arraySize - 1);

        int temp = array[i]; // Zmienna tymczasowa przechowuje bieżący element
        int j = i + 1; // Ustawia indeks pomocniczy na kolejny element po bieżącym

        // Pętla przechodzi przez pozostałe elementy większe od bieżącego elementu
        while ((j < arraySize) && (temp > array[j]))
        {
            array[j - 1] = array[j]; // Przesuwa większe elementy o jedną pozycję w lewo
            j++; // Przechodzi do następnego elementu
        }
        array[j - 1] = temp; // Umieszcza bieżący element w odpowiedniej pozycji
    }
}

void mergeSort(int tab[], int pom[], int poczatek, int koniec)
{
        // Obliczenie środka tablicy
        int srodek = (poczatek + koniec + 1) / 2;

        std::cout << "mergeSort na przedzialach " << poczatek << ", " << koniec << '\n';

        if (poczatek == koniec)
        {
            std::cout << "Jeden element, koniec rekurencji." << '\n';
            return;
        }

        // Rekursywne wywołanie funkcji MergeSort dla lewej podtablicy
        mergeSort(tab, pom, poczatek, srodek - 1);
        // Rekursywne wywołanie funkcji MergeSort dla prawej podtablicy
        mergeSort(tab, pom, srodek, koniec);

        std::cout << "Laczenie przedzialow " << poczatek << ", " << srodek - 1 << " i " << srodek << ", " << koniec << '\n';

        // Deklaracja zmiennych pomocniczych do iterowania po podtablicach
        int i1 = poczatek;
        int i2 = srodek;

        // Scalanie podtablic
        for (int i = poczatek; i <= koniec; i++) {
            // Warunek wyboru elementu z lewej podtablicy
            if ((i1 == srodek) || ((i2 <= koniec) && (tab[i1] > tab[i2]))) {
                // Dodanie elementu z lewej podtablicy do tablicy pomocniczej
                pom[i] = tab[i2];
                // Zwiększenie indeksu i2 w prawej podtablicy
                i2++;
            }
            else {
                // Dodanie elementu z prawej podtablicy do tablicy pomocniczej
                pom[i] = tab[i1];
                // Zwiększenie indeksu i1 w lewej podtablicy
                i1++;
            }
        }

        // Kopiowanie elementów z tablicy pomocniczej do tablicy głównej
        for (int i = poczatek; i <= koniec; i++) {
            tab[i] = pom[i];
        }
    
}

int main()
{
    //tworzenie tablicy
    int wielkoscTablicy;
    std::cout << "Podaj wielekosc tablicy" << '\n';
    std::cin >> wielkoscTablicy;
    int* stworzonaTablica = makeArray(wielkoscTablicy);
    int* pomTablica = makeArray(wielkoscTablicy);

    //wypełnianie tablicy
    std::cout << "Podaj liczby" << '\n';
    instertToArray(stworzonaTablica, wielkoscTablicy);

    //Wybór algorytmu sortowania
    int wybor;
    std::cout << "Podaj algorytm sortowania" << '\n';
    std::cin >> wybor;
    switch (wybor)
    {
    default:
        break;
    case 1:
        bubbleSort(stworzonaTablica, wielkoscTablicy);
        break;
    case 2:
        selectionSort(stworzonaTablica, wielkoscTablicy);
        break;
    case 3:
        insertSort(stworzonaTablica, wielkoscTablicy);
        break;
    case 4:
        mergeSort(stworzonaTablica, pomTablica, 0, wielkoscTablicy);
        break;
    }

    //wyświetlanie posortowanej tablicy
    //showArray(stworzonaTablica, 0, wielkoscTablicy - 1);

    //zwalnianie pamięci (usuwanie tablicy)
    delete[] pomTablica;
    delete[] stworzonaTablica;
    return 0;

}