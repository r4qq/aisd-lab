#include <iostream>

void showArray(int* array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        //Wyświetlanie kolejnego znaku w tablicy
        std::cout << array[i] << " ";
    }
    //znak końca linii
    std::cout << '\n';
}

int* makeArray(int x)
{
    //tworzenie nowej tablicy dynamicznej
    int* newArray = new int[x];
    return newArray;
}

void instertToArray(int* array, int arraySize)
{
    int x;
    //pętla pobierająca znaki z terminala
    for (int i = 0; i < arraySize; i++) {
        std::cin >> x;
        array[i] = x;
    }
    //znak zakończenia tablicy 
    array[arraySize] = '\0';
}

void arrayPop(int* &array, int &arraySize)
{
    //pętla przesuwająca elementy o jeden w lewo 
    for (int i = 0; i < arraySize + 1; i++)
    {
        array[i] = array[i + 1];
    }
    arraySize--; //zmniejszanie wielkośći tablicy o 1
    array[arraySize] = '\0'; //znak końca talicy
    array[arraySize + 1] = NULL; 
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