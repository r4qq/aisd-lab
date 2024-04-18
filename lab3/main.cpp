#include <cstdlib>
#include <iostream>
#include <random>


struct stack {
  int maxSize;
  int topIndex;
  int *items;
};

struct stack* newStack(int capacity)
{
    struct stack* stck = new stack;

    stck->maxSize = capacity;
    stck->topIndex = -1;
    stck->items = new int[capacity];

    return stck;
}

int size(struct stack* stck)
{
    return (stck->topIndex + 1);
}

bool isFull(struct stack* stck)
{
    return (size(stck) == stck->maxSize) ? true : false;
}

bool isEmpty(struct stack* stck)
{
    return (stck->topIndex == -1) ? true : false;
}

void push(struct stack* stck, int x)
{
    if (isFull(stck))
        exit(EXIT_FAILURE);

    stck->topIndex++;
    stck->items[stck->topIndex] = x;
}

void pop(struct stack* stck)
{
    if (isEmpty(stck))
        exit(EXIT_FAILURE);
    else
    stck -> topIndex--;
}

void deleteStack(struct stack* stck) {
    delete[] stck->items; // Deallocate memory for the stack items
    delete stck; // Deallocate memory for the stack structure
}

void fillStack(struct stack* stck)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    for (int i = 0; i < 10; i++)
    {
        push(stck, dist(gen));
    }
}

void printStack(struct stack* stck)
{
    std::cout << "Zwieniono indeks elementu na " << stck ->topIndex << '\n';
    std::cout << "stck -> items[" << stck -> topIndex << "] = " << stck -> items[stck -> topIndex] << '\n';
}

int main()
{
    int stackSize = 20;

    stack* myStack = newStack(stackSize);

    fillStack(myStack);

    printStack(myStack);
    std::cout << "-------------------------------" << '\n';

    while (true)
    {
        int wybor;
        std::cin >> wybor;
        switch (wybor)
        {
        default:
            std::cout << "Nie ma takiego wyboru" << '\n';
            std::cout << "-------------------------------" << '\n';
            break;
        case 1:
            if (!isFull(myStack))
            {
                std::cout << "Podaj liczbe" << '\n';
                int liczba;
                std::cin >> liczba;
                push(myStack, liczba);
            }
            else
            {
                std::cout << "Stos pelen" << '\n';
            }
            printStack(myStack);
            std::cout << "-------------------------------" << '\n';

            break;
        case 2:
            if (!isEmpty(myStack))
            {
                pop(myStack);
            }
            else
            {
                std::cout << "Stos pusty" << '\n';
            }
            std::cout << "-------------------------------" << '\n';
            printStack(myStack);
            break;
        case 3:
            std::cout << myStack->items[0] << '\n';
            std::cout << "-------------------------------" << '\n';
            break;
        case 4:
            deleteStack(myStack);
            exit(EXIT_SUCCESS);
            break;
        }
    }
    return 0;
}