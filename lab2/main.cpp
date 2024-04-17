#include <iostream>

void showArray(int* array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';
}

int* makeArray(int x)
{
    int* newArray = new int[x + 1];
    return newArray;
}

void instertToArray(int* array, int arraySize)
{
    int x;
    for (int i = 0; i < arraySize; i++) {
        std::cin >> x;
        array[i] = x;
    }
    //znak zakończenia tablicy 
    array[arraySize] = '\0';
}

void arrayPop(int* &array, int &arraySize)
{
    for (int i = 0; i < arraySize + 1; i++)
    {
        array[i] = array[i + 1];
    }
    arraySize--;
    array[arraySize] = '\0';
}

int main()
{
     //tworzenie tablicy
    int wielkoscTablicy;
    std::cout << "Podaj wilekość tablicy" << '\n';
    std::cin >> wielkoscTablicy;
    int* stworzonaTablica = makeArray(wielkoscTablicy);

    //wypełnianie tablicy
    std::cout << "Podaj liczby" << '\n';
    instertToArray(stworzonaTablica, wielkoscTablicy);

    showArray(stworzonaTablica, wielkoscTablicy);

    arrayPop(stworzonaTablica, wielkoscTablicy);

    showArray(stworzonaTablica, wielkoscTablicy);

    //zwalnianie pamięci (usuwanie tablicy)
    delete[] stworzonaTablica; 
    return 0;
}