#include <vector>

using namespace std;

// return true if an array is non-increasing or non-decreasing otherwise return false

bool isMonotonic(vector<int> array)
{
    bool is_increasing = true;
    bool is_decreasing = true;

    for (int i = 1; i < array.size(); i++)
    {
        if (is_increasing && array[i] < array[i - 1])
        {
            is_increasing = false;
        }
        if (is_decreasing && array[i] > array[i - 1])
        {
            is_decreasing = false;
        }
    }
    return is_increasing || is_decreasing;
}