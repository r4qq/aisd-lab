#include <cstddef>
#include <cstdlib>
#include <iostream>

// Struktura elementu listy
struct element 
{
    int data;                    // Dane przechowywane w elemencie
    struct element *nextElement; // Wskaźnik na następny element
};

// Funkcja dodająca element na początek listy
void pushFront(element **head, int number)
{   
    // Tworzenie nowego elementu
    element *currentElement = new element[sizeof(element)];

    // Inicjalizacja danych nowego elementu
    currentElement -> data = number;
    currentElement -> nextElement = (*head);
    // Ustawienie nowego elementu jako początku listy
    *head = currentElement;
}

// Funkcja dodająca element na koniec listy
void pushBack(element **head, int number)
{
    // Jeśli lista jest pusta, dodaj pierwszy element 
    if (*head == NULL)
    {
        *head = new element[sizeof(element)];    // Alokacja pamięci na nowy element

        // Inicjalizacja danych pierwszego elementu
        (*head) -> data = number;
        (*head) -> nextElement = NULL;
    }
    else 
    {
        //W przeciwnym razie przejdź przez listę do ostatniego elementu
        element *currentElement = *head;

        while (currentElement -> nextElement != NULL) 
        {
            currentElement = currentElement -> nextElement;
        }

        currentElement -> nextElement = new element[sizeof(element)];    // Alokacja pamięci na nowy element za ostatnim elementem

        // Inicjalizacja danych nowego ostatniego elementu
        currentElement -> nextElement -> data = number;
        currentElement -> nextElement -> nextElement = NULL;
    }
}

// Funkcja wyświetlająca zawartość listy
void showList(element *head)
{
    std::cout << '\n';

    // Sprawdzenie, czy lista jest pusta
    if (head == NULL) 
    {   
        std::cout << "Pusta lista" << '\n';
    }
    else 
    {
        element *currentElement = head;
        do 
        {
            std::cout << currentElement -> data << " ";
            currentElement = currentElement -> nextElement;
        }
        while (currentElement != NULL);
    }
    std::cout << '\n';
}

// Funkcja zwracająca liczbę elementów w liście
int listSize(element *head)
{
    int counter = 0;

    // Jeżeli lista jes pusta, zwróć 0
    if (head == NULL) 
    {
        return 0;
    }
    else 
    {
        element *currentElement = head;
        //Zliczanie elementów w liście
        do 
        {
            counter++;
            currentElement = currentElement -> nextElement;
        }
        while (currentElement != NULL);
    }
    return counter;
}

// Funkcja dodająca element na określoną pozycję w liście
void pushByIndex(element **head, int number, int index)
{
    //Jeśli indeks jest równy zero, dodaj element na początek listy
    if (index == 0) 
    {
        pushFront(head, number);
    }
    else 
    {
        //Jesli indeks jest równy wielkości listy, dodaj element na koniec listy
        if (index == listSize(*head)) 
        {
            pushBack(head, number);
        }
        else 
        {
            // Przejście do elementu o poprzednim indeksie
            element *currentElement = *head;
            element *tmp;

            int i = 0;
            while (currentElement -> nextElement != NULL && i < index - 1)
            {
                currentElement = currentElement -> nextElement;
                i++; 
            }

            tmp = currentElement -> nextElement;    // Wstawienie nowego elementu na określoną pozycję
            
            currentElement -> nextElement = new element[sizeof(element)];    // Alokacja pamięci na nowy element

            // Inicjalizacja danych nowego elementu
            currentElement -> nextElement -> data = number;
            currentElement -> nextElement -> nextElement = tmp;
        }
    }
}

// Funkcja usuwająca pierwszy element listy
void popFront(element **head)
{
    element *tmp = NULL;
    
    // Sprawdzenie, czy lista nie jest pusta
    if (*head != NULL) 
    {
        tmp = (*head) -> nextElement;    // Przypisanie następnego elementu po usuwanym do zmiennej tymczasowej
        delete *head;    // Usunięcie pierwszego elementu listy
        *head = tmp;    // Ustawienie głowy listy na następny element
    }
}

// Funkcja usuwająca ostatni element listy
void popBack(element **head)
{
    // Sprawdzenie, czy lista jest pusta
    if (*head == NULL) 
    {
        *head = NULL;
    }
    else 
    {
        element *currentElement = *head;

        while (currentElement -> nextElement -> nextElement == NULL) 
        {
            // Przesuwanie wskaźnika do przedostatniego elementu
            currentElement = currentElement -> nextElement;
        }

        // Usunięcie ostatniego elementu
        delete currentElement -> nextElement;

        // Ustawienie wskaźnika ostatniego elementu na NULL, aby wskazywał na koniec listy
        currentElement -> nextElement = NULL;
    }
}

// Funkcja usuwająca element z listy na podanej pozycji
void popByIndex(element **head, int index)
{
    // Sprawdzenie, czy usuwany element jest pierwszym elementem listy
    if (index == 0) 
    {
        popFront(head);    // Jeśli tak, użyj funkcji popFront do usunięcia pierwszego elementu
    }
    else 
    {
        element *currentElement = *head;
        element *tmp;

        int i = 0;
        // Przeszukaj listę do momentu znalezienia elementu poprzedzającego usuwany
        while (currentElement -> nextElement != NULL && i < index - 1)
        {
            currentElement = currentElement -> nextElement;
            i++; 
        }

        tmp = currentElement -> nextElement;    // Zapisz wskaźnik na element do usunięcia

        // Usuń element z listy
        currentElement -> nextElement = tmp -> nextElement;
        delete tmp;
    }
}

// Funkcja wyświetlająca menu
void showMenu()
{
    std::cout << "1. Push an item to the head of the list" << '\n';
    std::cout << "2. Push an item to the tail of the list" << '\n';
    std::cout << "3. Push an item to specific index of the list" << '\n';
    std::cout << "4. Pop an item from the head of the list" << '\n';
    std::cout << "5. Pop an item from the tail of the list" << '\n';
    std::cout << "6. Pop an item from the specific index of the list" << '\n';
    std::cout << "0. Close the program" << '\n';
    std::cout << "-------------------------------------------------" << '\n';
}

int main()
{
    element *lista = nullptr;    // Tworzenie listy
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
                int dataToAddFront;
                std::cout << "Podaj liczbę: ";
                std::cin >> dataToAddFront;
                pushFront(&lista, dataToAddFront); 
                break;
            case 2:
                int dataToAddBack;
                std::cout << "Podaj liczbę: ";
                std::cin >> dataToAddBack;
                pushBack(&lista, dataToAddBack); 
                break;
            case 3:
                int dataToAddAtIndex, index;
                std::cout << "Podaj liczbę: ";
                std::cin >> dataToAddAtIndex;
                std::cout << "Podaj indeks: ";
                std::cin >> index;
                pushByIndex(&lista, dataToAddAtIndex, index);
                break;
            case 4:
                popFront(&lista); 
                break;
            case 5:
                popBack(&lista); 
                break;
            case 6:
                int indexToRemove;
                std::cout << "Podaj indeks: ";
                std::cin >> indexToRemove;
                popByIndex(&lista, indexToRemove); 
                break;
            case 0:
                delete lista; // Usunięcie listy
                exit(0);
            default:
                std::cout << "Nie ma takiego wyboru" << '\n';
                break;
        }
    }


    return 0;
}