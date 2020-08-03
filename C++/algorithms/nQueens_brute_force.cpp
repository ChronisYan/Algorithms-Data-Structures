#include <iostream>

// Given a N x N chessboard (N >= 4) place N queens so that no one can attack each other
void displayer(int array[], int l)
{
    std::cout << "[ ";
    for (int i = 0; i < l; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int abs(int num)
{
    return num < 0 ? -num : num;
}

// cells [i1, j1] and [i2, j2] are on the same diagonal, if and only if|i1 − i2| = |j1 − j2|
bool is_solution(int perm[], int n) // diagonal check
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(i - j) == abs(perm[i] - perm[j]))
            {
                return false;
            }
        }
    }
    return true;
}

// Generate and check all board permutations (https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/)
// we know that each row and each column will have 1 Queen only.
// The permutations of an array length N, represent all positions that satisfy this condition
void valid_queen_position(int array[], int size, int n)
{
    if (size == 1)
    {
        // is_solution validates diagonal positions
        if (is_solution(array, n))
        {
            displayer(array, n);
        }
        return;
    }

    for (int i = 0; i < size; i++)
    {
        valid_queen_position(array, size - 1, n);

        // if size is odd, swap first and last element
        if (size % 2 == 1)
        {
            int temp = array[0];
            array[0] = array[size - 1];
            array[size - 1] = temp;
        }
        // If size is even, swap ith and last element
        else
        {
            int temp = array[i];
            array[i] = array[size - 1];
            array[size - 1] = temp;
        }
    }
}

int main()
{
    int N = 8;
    int board_state[N] = {0, 1, 2, 3, 4, 5, 6, 7};
    valid_queen_position(board_state, N, N);
    return 0;
}
