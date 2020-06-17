#include <iostream>
#include <vector>

std::vector<int> prime_factorization(int N)
{
    std::vector<int> prime_factors;

    // Starting from i=2 and going up to sqrt(N) if i divides N, add this to the list of prime factors and remove all
    // occurrences of i by repetitively dividing N by i
    for (int i = 2; i * i < N; i++)
    {
        if (N % i == 0)
        {

            prime_factors.push_back(i);
            while (N % i == 0)
            {
                N /= i;
            }
        }
    }

    // If we do not end up with 1, that means N has a prime factor > sqrt(N)
    // This prime factor is the number we are left with since it’s power will be 1 (as discussed earlier).
    if (N > 1)
    {
        prime_factors.push_back(N);
    }

    return prime_factors;
}

int main()
{
    int n = 35;
    std::vector<int> result = prime_factorization(n);

    // Display result:
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}