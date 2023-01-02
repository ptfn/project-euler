#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define N 600851475143

bool isprime(uint64_t n)
{
    for (uint64_t i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    for (uint64_t i = 2; i < N; i++)
        if (N % i == 0 && isprime(i))
            printf("%ld\n", i);
}