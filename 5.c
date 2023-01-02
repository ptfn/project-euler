#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool div(uint64_t n)
{
    for (int i = 1; i <= 20; i++)
        if (n % i != 0)
            return false;
    return true;
}

int main()
{
    uint64_t i = 1;
    while (1) {
        if (div(i)) {
            printf("%ld\n", i);
            break;
        } else
            i++;
    }
}