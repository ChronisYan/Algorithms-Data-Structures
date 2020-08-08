#include <iostream>

int fib_naive(int n)
{
    if (n <= 1)
        return n;

    return fib_naive(n - 1) + fib_naive(n - 2);
}

long long int fib(int n)
{
    long long int lastFib[2] = {0, 1};

    if (n <= 1)
        return lastFib[0];

    for (int i = 2; i <= n; i++)
    {
        long long int temp = lastFib[1];
        lastFib[1] = lastFib[0] + lastFib[1];
        lastFib[0] = temp;
    }

    return lastFib[1];
}

int main()
{
    int N = 15;
    int result1 = fib_naive(N);
    long long int result2 = fib(N);

    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;
}