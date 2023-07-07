#include <stdint.h>
#include <stdio.h>

#define N 4000000

void next_fib(uint64_t* a, uint64_t* b)
{
    uint64_t temp = *a + *b;
    *a = *b;
    *b = temp;
}

int main()
{
    uint64_t sum = 0, a = 0, b = 1;
    while (b <= N) {
        if (b % 2 == 0)
            sum += b;
        next_fib(&a, &b);
    }
    printf("\n%ld\n", sum);
}