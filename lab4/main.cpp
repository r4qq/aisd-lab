#include <cstddef>
#include <cstdlib>
#include <iostream>

struct element 
{
    int data;
    struct element *nextElement;
};

void pushFront(element **head, int number)
{
    element *currentElement = new element[sizeof(element)];

    currentElement -> data = number;
    currentElement -> nextElement = (*head);
    *head = currentElement;
}

void pushBack(element **head, int number)
{
    if (*head == NULL)
    {
        *head = new element[sizeof(element)];
        (*head) -> data = number;
        (*head) -> nextElement = NULL;
    }
    else 
    {
        element *currentElement = *head;

        while (currentElement -> nextElement != NULL) 
        {
            currentElement = currentElement -> nextElement;
        }

        currentElement -> nextElement = new element[sizeof(element)];
        currentElement -> nextElement -> data = number;
        currentElement -> nextElement -> nextElement = NULL;
    }
}

void showList(element *head)
{
    std::cout << '\n';
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

int listSize(element *head)
{
    int counter = 0;
    if (head == NULL) 
    {
        return 0;
    }
    else 
    {
        element *currentElement = head;
        do 
        {
            counter++;
            currentElement = currentElement -> nextElement;
        }
        while (currentElement != NULL);
    }
    return counter;
}

void pushByIndex(element **head, int number, int index)
{
    if (index == 0) 
    {
        pushFront(head, number);
    }
    else 
    {
        if (index == listSize(*head)) 
        {
            pushBack(head, number);
        }
        else 
        {
            element *currentElement = *head;
            element *tmp;

            int i = 0;
            while (currentElement -> nextElement != NULL && i < index - 1)
            {
                currentElement = currentElement -> nextElement;
                i++; 
            }

            tmp = currentElement -> nextElement;
            
            currentElement -> nextElement = new element[sizeof(element)];
            currentElement -> nextElement -> data = number;
            currentElement -> nextElement -> nextElement = tmp;
        }
    }
}

void popFront(element **head)
{
    element *tmp = NULL;
    if (*head != NULL) 
    {
        tmp = (*head) -> nextElement;
        delete *head;
        *head = tmp;
    }
}

void popBack(element **head)
{
    if (*head == NULL) 
    {
        *head = NULL;
    }
    else 
    {
        element *currentElement = *head;

        while (currentElement -> nextElement -> nextElement == NULL) 
        {
            currentElement = currentElement -> nextElement;
        }

        delete currentElement -> nextElement;

        currentElement -> nextElement = NULL;
    }
}

void popByIndex(element **head, int index)
{
    if (index == 0) 
    {
        popFront(head);
    }
    else 
    {
        element *currentElement = *head;
        element *tmp;

        int i = 0;
        while (currentElement -> nextElement != NULL && i < index - 1)
        {
            currentElement = currentElement -> nextElement;
            i++; 
        }

        tmp = currentElement -> nextElement;
        currentElement -> nextElement = tmp -> nextElement;
        delete tmp;
    }
}

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
    element *lista = nullptr;
    int wybor = -1;
    int zmienna;

    while (wybor) 
    {
        showList(lista); 

        std::cout << "Polecenie: ";
        std::cin >> wybor;

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
                delete lista;
                exit(0);
            default:
                std::cout << "Nie ma takiego wyboru" << '\n';
                break;
        }
    }


    return 0;
}