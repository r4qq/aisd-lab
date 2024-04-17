#include <iostream>
#include <utility>


void showArray(int* array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        //Wyświetlanie kolejnego znaku w tablicy
        std::cout << array[i] << " ";
    }
    //koniec wyswietlania
    std::cout << '\n';
    std::cout << "-----------------------------------";
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
}

void arrayPop(int* array, int& arraySize)
{
    //pętla przesuwająca elementy o jeden w lewo 
    for (int i = 0; i < arraySize - 1; ++i)
    {
        array[i] = array[i + 1];
    }
    --arraySize; //zmniejszanie wielkośći tablicy o 1 
}

void swapDown(int* heap, int i, int heapSize)
{
    int max = i;
    int leftElement = (2 * i) + 1;
    int rightElement = (2 * i) + 2;
    //sprawdzanie czy lewy potomek jest większy
    if (leftElement < heapSize && heap[leftElement] > heap[max])
    {
        max = leftElement;
    }
    //sprawdzanie czy prawy potomek jest większy
    if (rightElement < heapSize && heap[rightElement] > heap[max])
    {
        max = rightElement;
    }

    //zamień miejscami jeśli znaleziono większego potomka
    if (max != i) 
    {
        std::swap(heap[i], heap[max]);
        swapDown(heap, max, heapSize);
    }
}

void heapify(int* heap, int heapSize)
{
    //Przechodzenie przez elementy od połowy korzenia
    for (int i = heapSize / 2; i >= 0; --i)
    {
        swapDown(heap, i, heapSize);
    }
}

void heapInsert(int*& heap, int& heapSize, int element)
{
    ++heapSize; // rozmiar kopca więlszy o 1
    int* newHeap = new int[heapSize]; //alokacja pamieci nowego kopca

    //kopiowanie elementów do nowego kopca
    for (int i = 0; i < heapSize - 1; ++i) 
    {
        newHeap[i] = heap[i];
    }

    newHeap[heapSize - 1] = element; //wstawienie nowego elementu na ostatnie miejsce w kopcu

    int x = heapSize - 1;

    //przsuwanie nowego elementu na ostatnie miejsce kopca
    while (x > 0 && newHeap[x] > newHeap[(x - 1)/2]) 
    {
        std::swap(newHeap[x], newHeap[(x - 1)/2]);
        x = (x - 1) / 2;
    } 
    delete[] heap; // zwolnienie pamieci po startym kopcu
    heap = newHeap; // przypisanie nowego kopca
    //delete[] newHeap; 
}

void heap_pop(int*& heap, int& heapSize)
{
    heap[0] = heap[(heapSize - 1)]; // zamiana korzenia z ostatnim elementem kopca
    heapSize--; // zmiejszenie rozmiaru o 1

    int* newHeap = new int[heapSize]; // alokacja pamieci na nowy kopiec

    //kopiowanie elementow do nowego kopca (oprocz ostatniego)
    for (int i = 0; i < heapSize; ++i) 
    {
        newHeap[i] = heap[i];
    }

    delete[] heap; // zwolnienie pamieci po kopcu
    heap = newHeap; //przypisanie nowego kopca
    heapify(heap, heapSize);      //naprawa kopca
}

void heapSort(int* heap, int heapSize)
{
    heapify(heap, heapSize); // budowanie kopca

    //wyciaganie elementow po jednym i ponowne budowanie kopca
    for (int i = heapSize - 1; i > 0; i--) {
        std::swap(heap[0], heap[i]); // zamiana korzenia (największego elementu) z ostatnim elementem tablicy
        heapify(heap, heapSize); // budowa kopca
    }
}

int main()
{
     //tworzenie tablicy
    int wielkoscTablicy;
    std::cout << "Podaj wilekosc kopca" << '\n';
    std::cin >> wielkoscTablicy;
    int* stworzonaTablica = makeArray(wielkoscTablicy);

    //wypełnianie tablicy
    std::cout << "Podaj liczby" << '\n';
    instertToArray(stworzonaTablica, wielkoscTablicy);
    std::cout << "-----------------------------------" << '\n';

    //petla menu
    while (true) 
    {
        int wybor;
        std::cin >> wybor;
        switch (wybor) 
        {
            default:
                break;
            case 1:
                //dodawanie elementu do kopca
                std::cout << "Daj element" << '\n';
                int element;
                std::cin >> element;
                heapInsert(stworzonaTablica, wielkoscTablicy, element);
                std::cout << "Nowy kopiec: " << '\n';
                showArray(stworzonaTablica, wielkoscTablicy); //wyswietlanie kopca w formie tablicy
                break;
            case 2:    
                //usuwanie pierwszego elementu z kopca
                std::cout << "Nowy kopiec po popie" << '\n';
                heap_pop(stworzonaTablica, wielkoscTablicy);
                showArray(stworzonaTablica, wielkoscTablicy); //wyswietlanie kopca w formie tablicy
                break;
            case 3:
                //heapsort
                std::cout << "Heapsort: " << '\n';
                heapSort(stworzonaTablica, wielkoscTablicy);
                showArray(stworzonaTablica, wielkoscTablicy);//wyswietlanie kopca w formie tablicy
                break;
            case 4:
                //usuwanie pierwszego elementu z listy
                std::cout << "Test arrayPopa" << "\n";
                arrayPop(stworzonaTablica, wielkoscTablicy);
                showArray(stworzonaTablica, wielkoscTablicy); //wyswietlanie kopca w formie tablicy
                break;
            case 5:
                //zwalnianie pamięci (usuwanie tablicy)
                delete[] stworzonaTablica; 
                //wyjście z programu
                exit(0);
        }
    }
    
    return 0;
}