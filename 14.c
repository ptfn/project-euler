#include <stdint.h>
#include <stdio.h>
#define N 1000000

struct collatz_number {
    uint64_t max;
    uint64_t number;
} max = {0, 0};

uint64_t collatz(uint64_t n)
{
    uint64_t i = 1;
    while (1) {
        if (n == 1)
            break;
        else if (!(n&1))
            n /= 2;
        else
            n = 3 * n + 1;
        i++;
    }
    return i;
}

int main()
{
    for (uint64_t i = 1; i++ < N; )
        if (max.max < collatz(i)) {
            max.max = collatz(i);
            max.number = i;
        }
    printf("%ld\t%ld\n", max.max, max.number);
}
