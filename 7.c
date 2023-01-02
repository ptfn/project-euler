#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool isprime(int n)
{
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    uint64_t i = 1,  N = 10001;
    while (N > 0)
        if (isprime(++i))
            N--;
    printf("%ld\n", i);
}