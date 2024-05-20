#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

// Struktura elementu listy
struct element
{
    int data;                    // Dane przechowywane w elemencie
    int priority;                // Priorytet elementu
    struct element* nextElement; // Wskaźnik na następny element
};

// Funkcja wyświetlająca zawartość listy
void showList(element* head)
{
    std::cout << '\n';

    // Sprawdzenie, czy lista jest pusta
    if (head == NULL)
    {
        std::cout << "Pusta lista" << '\n';
    }
    else
    {
        // Zmienna pomocnicza do przechodzenia przez listę
        element* currentElement = head;
        do
        {
            // Wyświetlenie danych i priorytetu bieżącego elementu
            std::cout << currentElement->data << ":" << currentElement->priority << " ";
            // Przejście do następnego elementu
            currentElement = currentElement->nextElement;
        } while (currentElement != NULL);
    }
    std::cout << '\n';
}

// Funkcja dodająca element do listy zgodnie z jego priorytetem
void pushByPriority(element** head, int numberNew, int priorityNew)
{
    // Jeśli lista jest pusta, dodaj pierwszy element 
    if (*head == NULL)
    {
        *head = new element[sizeof(element)];    // Alokacja pamięci na nowy element

        // Inicjalizacja danych pierwszego elementu
        (*head)->priority = priorityNew;
        (*head)->data = numberNew;
        (*head)->nextElement = NULL;
    }
    else
    {
        // Tworzenie nowego elementu
        element* newElement = new element;
        newElement->priority = priorityNew;
        newElement->data = numberNew;
        newElement->nextElement = NULL;

        // Sprawdzenie, czy nowy element powinien być pierwszym elementem
        if (priorityNew < (*head)->priority) 
        {
            newElement->nextElement = *head;
            *head = newElement;
        }
        else 
        {
            // Znalezienie odpowiedniego miejsca na nowy element
            element* currentElement = *head;
            while (currentElement->nextElement != NULL && priorityNew >= currentElement->nextElement->priority) 
            {
                currentElement = currentElement->nextElement;
            }
            // Wstawienie nowego elementu do listy
            newElement->nextElement = currentElement->nextElement;
            currentElement->nextElement = newElement;
        }
        delete newElement;
    }
}

// Funkcja usuwająca ostatni element listy
void popBack(element** head)
{
    // Sprawdzenie, czy lista jest pusta
    if (*head == NULL)
    {
        *head = NULL;
    }
    else
    {
        element* currentElement = *head;

        // Przesuwanie wskaźnika do przedostatniego elementu
        while (currentElement->nextElement->nextElement != NULL)
        {
            currentElement = currentElement->nextElement;
        }

        // Usunięcie ostatniego elementu
        delete currentElement->nextElement;

        // Ustawienie wskaźnika ostatniego elementu na NULL, aby wskazywał na koniec listy
        currentElement->nextElement = NULL;
    }
}

// Funkcja wyświetlająca menu
void showMenu()
{
    std::cout << "1. Push an item by priority" << '\n';
    std::cout << "2. Pop an item with the highest priority" << '\n';
    std::cout << "0. Close the program" << '\n';
    std::cout << "-------------------------------------------------" << '\n';
}

int main()
{
    element* lista = NULL;    // Tworzenie listy
    int wybor = -1;

    // Menu programu
    while (wybor)
    {
        showMenu(); // Wyświetlnienie menu
        showList(lista);    // Wyświetlnie listy 

        std::cout << "Polecenie: ";
        std::cin >> wybor; // Pobranie polecenia

        switch (wybor)
        {
            case 1:
            {
                int dataToAddByPriority, priority;
                std::string input;
                char delimeter;
                // Pobranie danych od użytkownika
                std::cin >> input;
                std::stringstream ss(input);
                ss >> dataToAddByPriority;
                ss >> delimeter;
                ss >> priority;
                // Sprawdzenie poprawności formatu danych
                if (ss.fail() || delimeter != ':') 
                {
                    std::cout << "Złe formatowanie" << '\n';
                }
                else 
                {
                    // Dodanie elementu z priorytetem
                    pushByPriority(&lista, dataToAddByPriority, priority);            
                }
                break;
            }
            case 2:
            {
                // Usunięcie elementu z najwyższym priorytetem
                popBack(&lista);
                break;
            }
            case 0:
            {
                // Usunięcie listy i zakończenie programu
                delete lista; // Usunięcie listy
                exit(0);
            }
            default:
            {
                std::cout << "Nie ma takiego wyboru" << '\n';
                break;
            }
        }
    }
    return 0;
}
