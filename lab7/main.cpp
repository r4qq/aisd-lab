#include <iostream>
#include <random>

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

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for(int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    for (int i = 0; max / i > 0; i *= 10) 
    {
        countSort(arr, n, i);
    }
}

int main()
{
    int n = 100;
    int arr[n];

    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1,100);

    for(int i = 1; i <= n; i++)
    {
        arr[i] = uniform_dist(e1);

        print(arr, n);
        radixSort(arr, n);
        print(arr, n);
    }
}