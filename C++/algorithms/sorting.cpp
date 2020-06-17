#include <iostream>
#include <stdlib.h>

template <class T>
void displayer(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
template <class T>
void suffler(T arr[], int size)
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
void selection_sort(T arr[], int size)
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

// BUBBLE SORT
template <class T>
void bubble_sort(T arr[], int size)
{
    int unsorted = size - 1;
    bool swap;

    do
    {
        swap = false;
        for (int i = 0; i < unsorted; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                T temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = true;
            }
        }
        unsorted--;
    } while (swap);
}

// INSERTION SORT
template <class T>
void insertion_sort(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int j = i;
        while (j >= 1 && arr[j] < arr[j - 1])
        {
            T temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

// MERGE SORT
template <class T>
void merge(T arr[], int start, int mid, int end)
{
    int sz1 = mid - start + 1;
    int sz2 = end - mid;
    int left[sz1], right[sz2];

    for (int i = 0; i < sz1; i++)
    {
        left[i] = arr[start + i];
    }
    for (int i = 0; i < sz2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    int l = 0, r = 0, a = start;
    while (l < sz1 && r < sz2)
    {
        if (left[l] < right[r])
        {
            arr[a] = left[l];
            l++;
        }
        else
        {
            arr[a] = right[r];
            r++;
        }
        a++;
    }
    while (l < sz1)
    {
        arr[a] = left[l];
        a++;
        l++;
    }
    while (r < sz2)
    {
        arr[a] = right[r];
        a++;
        r++;
    }
}

template <class T>
void merge_sort(T arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;

    merge_sort<T>(arr, start, mid);
    merge_sort<T>(arr, mid + 1, end);

    merge<T>(arr, start, mid, end);
}

// QUICK SORT
template <class T>
int partition(T arr[], int low, int high)
{
    T pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            T temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    T temp = arr[high];
    arr[high] = arr[i + 1];
    arr[i + 1] = temp;
    return (i + 1);
}

template <class T>
void quick_sort(T arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pi = partition(arr, low, high);

    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
}

int main()
{
    int size = 15;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = (std::rand() % 100) + 1;
    }
    std::cout << "\n-----------SELECTION SORT-----------\n";
    displayer(array, size);
    selection_sort<int>(array, size);
    displayer(array, size);
    std::cout << "------------------------------------\n";

    suffler(array, size);

    std::cout << "\n-----------BUBBLE SORT-----------\n";
    displayer(array, size);
    bubble_sort<int>(array, size);
    displayer(array, size);
    std::cout << "------------------------------------\n";

    suffler(array, size);

    std::cout << "\n-----------INSERTION SORT-----------\n";
    displayer(array, size);
    insertion_sort<int>(array, size);
    displayer(array, size);
    std::cout << "------------------------------------\n";

    suffler(array, size);

    std::cout << "\n-----------MERGE SORT-----------\n";
    displayer(array, size);
    merge_sort<int>(array, 0, size);
    displayer(array, size);
    std::cout << "------------------------------------\n";

    suffler(array, size);

    std::cout << "\n-----------QUICK SORT-----------\n";
    displayer(array, size);
    quick_sort<int>(array, 0, size - 1);
    displayer(array, size);
    std::cout << "------------------------------------\n";
}