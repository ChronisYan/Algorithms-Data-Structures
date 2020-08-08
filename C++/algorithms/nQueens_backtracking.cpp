#include <iostream>
#include <vector>

// Backtracking algorithm: Main idea is to construct a recursive tree
// and cut its dead ends (partial permutations that cannot be solutions)

void displayer(std::vector<int> array)
{
    std::cout << "[ ";
    for (std::vector<int>::iterator it = array.begin(); it != array.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

int abs(int num)
{
    return num < 0 ? -num : num;
}

bool is_not_present(std::vector<int> &arr, int key)
{
    for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        if (*it == key)
            return false;
    }
    return true;
}

bool is_valid(std::vector<int> &arr)
{
    int i = arr.size() - 1;
    for (int j = 0; j < i; j++)
    {
        if (abs(i - j) == abs(arr[i] - arr[j]))
            return false;
    }
    return true;
}
int n_sol = 0;
void generate_permutations(std::vector<int> &perm, int n)
{
    if (perm.size() == n)
    {
        displayer(perm);
        n_sol++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        // if an number < N is not in our vector so far push it
        if (is_not_present(perm, i))
        {
            perm.push_back(i);

            // check if the board is valid and continue only if it is
            if (is_valid(perm))
                generate_permutations(perm, n);

            perm.pop_back();
        }
    }
}

int main()
{
    int N = 8;
    std::vector<int> board = {};
    generate_permutations(board, N);
    std::cout << n_sol << std::endl;
    return 0;
}
