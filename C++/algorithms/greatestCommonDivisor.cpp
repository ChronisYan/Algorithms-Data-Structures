#include <iostream>

long long unsigned int gcd(long long unsigned int a, long long unsigned int b)
{
    if (b == 0)
        return a;

    long long unsigned int a_prime = a % b;

    return gcd(b, a_prime);
}

int main()
{

    std::cout << gcd(3918848, 1653264) << std::endl;
}