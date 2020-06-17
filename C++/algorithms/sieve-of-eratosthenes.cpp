#include <iostream>
#include <vector>

// The sieve of Eratosthenes is a algorithm that finds prime numbers between 1 and N
// 1. Create a list of all numbers from 2 to N. Initially, all numbers are unmarked.
// 2. Starting from p=2, mark all multiples of 2 less than or equal to N.
// 3. Move to the next unmarked number, i.e., p=3. Mark all its multiples.
// Stop if p > sqrt(N)

std::vector<bool> primes_to_N(int N)
{
    std::vector<bool> is_prime(N + 1, true);

    for (int i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i + i; j <= N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

int main()
{
    int n = 30;
    std::vector<bool> prime_list = primes_to_N(n);

    for (int i = 2; i <= n; i++)
    {
        if (prime_list[i])
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}