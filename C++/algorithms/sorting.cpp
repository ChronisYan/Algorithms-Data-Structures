#include <iostream>
#include <stdlib.h>

template <class T>
void displayer(T *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
template <class T>
void suffler(T *arr, int size)
{
    int newPos;
    for (int i = size - 1; i > 0; i--)
    {
        newPos = std::rand() % (i + 1);
        T temp = arr[i];
        arr[i] = arr[newPos];
        arr[newPos] = temp;
    }
}

// SELECTION SORT
template <class T>
void selection(T *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main()
{
    int size = 10;
    int *ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = (std::rand() % 100) + 1;
    }
    std::cout << "\n-----------SELECTION SORT-----------\n";
    displayer(ptr, size);
    selection<int>(ptr, size);
    displayer(ptr, size);
    std::cout << "------------------------------------\n";

    // displayer(ptr, size);

    delete[] ptr;
}