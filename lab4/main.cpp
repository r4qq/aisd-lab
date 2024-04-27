#include <cstddef>
#include <iostream>

struct element 
{
    int data;
    struct element* nextElement;
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
        element* currentElement = *head;

        while (currentElement -> nextElement != NULL) 
        {
            currentElement = currentElement -> nextElement;
        }

        currentElement -> nextElement = new element[sizeof(element)];
        currentElement -> nextElement -> data = number;
        currentElement -> nextElement -> nextElement = NULL;
    }
}

void showList(element* head)
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

int listSize(element* head)
{
    int counter = 0;
    if (head == NULL) 
    {
        return 0;
    }
    else 
    {
        element* currentElement = head;
        do 
        {
            counter++;
            currentElement = currentElement -> nextElement;
        }
        while (currentElement != NULL);
    }
    return counter;
}

int main()
{

    return 0;
}