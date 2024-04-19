#include <cstdlib>
#include <iostream>
#include <random>


// Struktura stosu
struct stack {
  int maxSize;  // Maksymalny rozmiar stosu
  int topIndex; // Indeks wierzchołka stosu
  int *items;   // Tablica przechowująca elementy stosu
};

// Funkcja tworząca nowy stos 
struct stack* newStack(int capacity)
{
    struct stack* stck = new stack;  // Tworzymy nowy stos

    stck->maxSize = capacity;         // Ustawiamy maksymalny rozmiar stosu
    stck->topIndex = -1;              // Ustawiamy indeks wierzchołka stosu na -1, co oznacza pusty stos
    stck->items = new int[capacity];  // Tworzymy tablicę o rozmiarze capacity dla przechowywania elementów

    return stck;  // Zwracamy wskaźnik do nowego stosu
}

// Funkcja zwracająca aktualny rozmiar stosu
int size(struct stack* stck)
{
    return (stck->topIndex + 1);  
}

// Funkcja sprawdzająca, czy stos jest pełny
bool isFull(struct stack* stck)
{
    return (size(stck) == stck->maxSize) ? true : false;  
}

// Funkcja sprawdzająca, czy stos jest pusty
bool isEmpty(struct stack* stck)
{
    return (stck->topIndex == -1) ? true : false;  
}

// Funkcja dodająca element na wierzch stosu
void push(struct stack* stck, int x)
{
    if (isFull(stck))                // Jeśli stos jest pełny, kończymy program z kodem błędu
        exit(EXIT_FAILURE);

    stck->topIndex++;                // Zwiększamy indeks wierzchołka
    stck->items[stck->topIndex] = x; // Umieszczamy element na wierzchu stosu
}

// Funkcja usuwająca element z wierzchu stosu
void pop(struct stack* stck)
{
    if (isEmpty(stck))            // Jeśli stos jest pusty, kończymy program z kodem błędu
        exit(EXIT_FAILURE);
    else
        stck -> topIndex--;       // Zmniejszamy indeks wierzchołka, co efektywnie usuwa element
}

int returnElement(struct stack* stck)
{
    return stck -> items[stck -> topIndex];
}

// Funkcja usuwająca stos i zwalniająca pamięć
void deleteStack(struct stack* stck) {
    delete[] stck->items; // Zwalniamy pamięć zaalokowaną na tablicę elementów stosu
    delete stck;          // Zwalniamy pamięć zaalokowaną na strukturę stosu
}

// Funkcja wypełniająca stos losowymi liczbami
void fillStack(struct stack* stck)
{
    std::random_device rd;          // Tworzymy obiekt generatora liczb losowych
    std::mt19937 gen(rd());    // Inicjujemy generator liczb losowych za pomocą ziarna z urządzenia losowego
    std::uniform_int_distribution<int> dist(1, 10); // Tworzymy dystrybucję liczb całkowitych z zakresu od 1 do 10

    for (int i = 0; i < 10; i++)   // Wypełniamy stos 10 losowymi liczbami
    {
        push(stck, dist(gen));  // Dodajemy losową liczbę na wierzch stosu
    }
}

// Funkcja wyświetlająca informacje o stanie stosu
void printStackInfo(struct stack* stck)
{
    if((stck -> topIndex) != -1 )
    {
        std::cout << "Zmieniono indeks elementu na " << stck ->topIndex << '\n';  
        std::cout << "stck -> items[" << stck -> topIndex << "] = " << stck -> items[stck -> topIndex] << '\n';
    }
    else 
    {
        std::cout << "Stos pusty" << '\n';
    }  
}

// Funkcja wyświetlająca zawartość stosu od najmłodszego do najstarszego
void printStack(struct stack* stck)
{
    for (int i = stck -> topIndex; i >= 0; i--) {  
        std::cout << i << ": " << stck -> items[i] << '\n';  
    }  
}

// Główna funkcja programu
int main()
{
    int stackSize = 20;  // Określenie rozmiaru stosu

    stack* myStack = newStack(stackSize);  // Tworzenie nowego stosu

    fillStack(myStack);  // Wypełnianie stosu losowymi liczbami

    std::cout << "Stos top -> bottom" << '\n';
    printStack(myStack);  // Wyświetlanie zawartości stosu

    //Wyświetlenie menu
    std::cout << "-------------------------------" << '\n';
    std::cout << "1. Dodawanie elementu do stosu" << '\n';
    std::cout << "2. Usuwanie elemntu ze stosu" << '\n';
    std::cout << "3. Zwrocenie (wyswietlenie) pierwszego elemntu stosu" << '\n';
    std::cout << "4. Wyjscie z programu" << '\n';
    std::cout << "-------------------------------" << '\n';  

    while (true)  
    {
        int wybor;  
        std::cin >> wybor;  // Wczytywanie wyboru użytkownika
        switch (wybor)  
        {
        default:  
            std::cout << "Nie ma takiego wyboru" << '\n';  
            std::cout << "-------------------------------" << '\n'; 
            break;
        case 1:  
            if (!isFull(myStack))  // Sprawdzenie, czy stos nie jest pełny
            {
                std::cout << "Podaj liczbe" << '\n';  
                int liczba;  
                std::cin >> liczba;  
                push(myStack, liczba);  // Dodawanie liczby na stos
                printStackInfo(myStack);  // Wyświetlanie informacji o stanie stosu
            }
            else
            {
                std::cout << "Stos pelen" << '\n';
            }
            std::cout << "-------------------------------" << '\n';  
            break;
        case 2:  
            if (!isEmpty(myStack))  // Sprawdzenie, czy stos nie jest pusty
                pop(myStack);  // Usuwanie elementu ze stosu
            printStackInfo(myStack);  // Wyświetlanie informacji o stanie stosu
            std::cout << "-------------------------------" << '\n';  
            break;
        case 3:  
            std::cout << "Zwracanie elementu na wierzchu stosu" << '\n';
            std::cout << returnElement(myStack) << '\n';  // Wyświetlanie elementu z wierzchu stosu
            std::cout << "-------------------------------" << '\n';  
            break;
        case 4:  
            deleteStack(myStack);  // Usuwanie stosu
            exit(EXIT_SUCCESS);  // Zakończenie programu
            break;
        }
    }
    return 0;  
}