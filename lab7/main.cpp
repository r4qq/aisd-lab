#include <iostream>
#include <random>

// Funkcja zwracająca maksymalną wartość w tablicy
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    return mx;
}

// Funkcja do wyświetlania elementów tablicy
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

// Funkcja do sortowania za pomocą sortowania przez zliczanie
void countSort(int arr[], int n, int exp)
{
    int output[n]; // Tablica wyjściowa
    int count[10] = {}; // Tablica zliczająca cyfry
    print(count, 10); // Wyświetlanie tablicy count

    // Zliczanie wystąpień każdej cyfry w odpowiedniej pozycji
    for(int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    print(count, 10); // Wyświetlanie tablicy count

    // Modyfikowanie count aby zawierało pozycje wyjściowe cyfr
    for(int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Budowanie tablicy wyjściowej
    for(int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Kopiowanie tablicy wyjściowej do tablicy arr
    for(int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// Funkcja do sortowania Radix Sort
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n); // Znajdowanie maksymalnej wartości w tablicy

    std::cout << "max: " << max << '\n';

    // Wykonywanie sortowania dla każdej cyfry
    for (int i = 1; max / i > 0; i *= 10) 
    {
        if (i == 10)
            std::cout << " dwa" << '\n';

        if (i == 100)
            std::cout << " trzy"<< '\n';
        countSort(arr, n, i);
    }
}

int main()
{
    int n = 100;
    int arr[n];

    // Generowanie losowych liczb do tablicy
    std::random_device r;
    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> uniform_dist(1,100);

    for(int i = 0; i < n; i++)
    {
        arr[i] = uniform_dist(engine);
    }

    std::cout << "Przed radix sortem" << '\n';
    print(arr, n);
    radixSort(arr, n);
    std::cout << "Po radix sorcie" << '\n';
    print(arr, n);
}
