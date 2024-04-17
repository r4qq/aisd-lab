//Stanisław Rak 235IC B1
#include <iostream>

int* makeArray(int x)
{
    int* newArray = new int[x + 1];
    return newArray;
}

void instertToArray(int* array, int arraySize)
{
    int znak;
    for (int i = 0; i < arraySize; i++) {
        std::cin >> znak;
        array[i] = znak;
    }
    //znak zakończenia tablicy 
    array[arraySize] = '\0';
}

void selectionSort(int* array, int arraySize)
{
    //int temp, minIndex;
    for (int i = 0; i < arraySize - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < arraySize; ++j)
        {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

void bubbleSort(int* array, int arraySize)
{
    int temp;
    for (int i = 0; i < arraySize; ++i)
    {
        for (int j = 0; j < arraySize - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void selectSort(int* array, int arraySize)
{
    for (int i = arraySize - 2; i >= 0; i--) {
        int temp = array[i];
        int j = i + 1;
    while ((j < arraySize) && (temp > array[j]))
        {
            array[j-1] = array[j];
            j++;
        }
    array[j-1] = temp;
    }
}

void showArray(int* array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';
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
            selectSort(stworzonaTablica, wielkoscTablicy);
            break;
    }

    //wyświetlanie posortowanej tablicy
    showArray(stworzonaTablica, wielkoscTablicy);

    //zwalnianie pamięci (usuwanie tablicy)
    delete[] stworzonaTablica;
    return 0;

}