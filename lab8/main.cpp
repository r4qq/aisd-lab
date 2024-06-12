#include <iostream>
#include <ostream>
#include <vector>
#include "math.h"

// Struktura reprezentująca węzeł drzewa binarnego
struct Wezel
{
    Wezel *lewy;   // wskaźnik na lewego potomka
    Wezel *prawy;  // wskaźnik na prawego potomka
    int dane;      // wartość przechowywana w węźle
};

// Definicje węzłów drzewa binarnego
Wezel G = {NULL, NULL, 123};
Wezel H = {NULL, NULL, 32};
Wezel I = {NULL, NULL, 234};
Wezel J = {NULL, NULL, 1};
Wezel K = {NULL, NULL, 465};

Wezel D = {&H, &I, 76};
Wezel E = {&J, NULL, 290};
Wezel F = {&K, NULL, 34};
Wezel B = {&D, &E, 21};
Wezel C = {&F, &G, 20};

Wezel A = {&B, &C, 76};

// Funkcja do wyświetlania drzewa binarnego
void wyswietlDrzewo(std::vector<Wezel>* wezly)
{
    int j = 0;
    for(int i = 0; i < wezly->size(); i++)
    {
        if (i + 1 == pow(2, j)) 
        {
            std::cout << std::endl << std::endl;
            j++;
        }
    }

    int jj = j;
    j = 0;

    for(int i = 0; i < wezly->size(); i++)
    {
        if (i + 1 == pow(2, j)) 
        {
            std::cout << std::endl << std::endl;
            j++;
            jj--;
        }

        for(int k = 0; k <= jj + (wezly->size() - i)/10; k++)
        {
            std::cout << " ";
        }
        std::cout << (*wezly)[i].dane;
    }
}

// Funkcja do przechodzenia drzewa w porządku preorder
void preorder(Wezel* v)
{
    if(v)
    {
        std::cout << v->dane << " ";   // wyświetl wartość węzła
        preorder(v->lewy);             // przejdź do lewego potomka
        preorder(v->prawy);            // przejdź do prawego potomka
    }
}

// Funkcja do przechodzenia drzewa w porządku postorder
void postorder(Wezel *v)
{
    if (v) 
    {
        postorder((v->lewy));         // przejdź do lewego potomka
        postorder(v->prawy);          // przejdź do prawego potomka
        std::cout << v->dane << " ";  // wyświetl wartość węzła
    }
}

// Funkcja do przechodzenia drzewa w porządku inorder
void inorder(Wezel* v)
{
    if (v)
    {
        inorder(v->lewy);             // przejdź do lewego potomka
        std::cout << v->dane << " ";  // wyświetl wartość węzła
        inorder(v->prawy);            // przejdź do prawego potomka
    }
}

int main()
{
    // Tworzenie wektora przechowującego węzły drzewa
    std::vector<Wezel> *wezly = new std::vector<Wezel>();
    wezly->push_back(A);
    wezly->push_back(B);
    wezly->push_back(C);
    wezly->push_back(D);
    wezly->push_back(E);
    wezly->push_back(F);
    wezly->push_back(G);
    wezly->push_back(H);
    wezly->push_back(I);
    wezly->push_back(J);
    wezly->push_back(K);

    // Wyświetlanie drzewa
    wyswietlDrzewo(wezly);

    // Wyświetlanie przejścia preorder
    std::cout << std::endl << std::endl << "Preorder" << std::endl;
    preorder(&A);

    // Wyświetlanie przejścia inorder
    std::cout << std::endl << std::endl << "Inorder" << std::endl;
    inorder(&A);

    // Wyświetlanie przejścia postorder
    std::cout << std::endl << std::endl << "Postorder" << std::endl;
    postorder(&A);

    return 0; 
}
