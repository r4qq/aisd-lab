#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

// Struktura elementu listy
struct element
{
    int data;                    // Dane przechowywane w elemencie
    int priority;
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
        element* currentElement = head;
        do
        {
            std::cout << currentElement->data << ":" << currentElement->priority << " ";
            currentElement = currentElement->nextElement;
        } while (currentElement != NULL);
    }
    std::cout << '\n';
}


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
        element* newElement = new element;
        newElement -> priority = priorityNew;
        newElement -> data = numberNew;
        newElement -> nextElement = NULL;

        if (priorityNew < (*head) -> priority) 
        {
            newElement -> nextElement = *head;
            *head = newElement;
        }
        else 
        {
            element* currentElement = *head;
            while (currentElement -> nextElement != NULL && priorityNew >= currentElement -> nextElement -> priority) 
            {
                currentElement = currentElement -> nextElement;
            }
            newElement -> nextElement = currentElement -> nextElement;
            currentElement -> nextElement = newElement;
        }
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

        while (currentElement->nextElement->nextElement != NULL)
        {
            // Przesuwanie wskaźnika do przedostatniego elementu
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
                std::cin >> input;
                std::stringstream ss(input);
                ss >> dataToAddByPriority;
                ss >> delimeter;
                ss >> priority;
                if (ss.fail() || delimeter != ':') 
                {
                    std::cout << "Złe formatowanie" << '\n';
                }
                else 
                {
                pushByPriority(&lista, dataToAddByPriority, priority);            
                }
                break;
            }
            case 2:
            {
                popBack(&lista);
                break;
            }
            case 0:
            {
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