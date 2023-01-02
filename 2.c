#include <stdint.h>
#include <stdio.h>

#define N 100

void next_fib(uint64_t *a, uint64_t *b)
{
    uint64_t temp = *a + *b;
    *a = *b;
    *b = temp;
}

int main()
{
    uint64_t i = 0 ,sum = 0, a = 1, b = 2;

    for (i; i < N; i++, next_fib(&a, &b))
        if (b % 2 == 0) {
            sum += b;
            if (sum > 4000000) 
                break;
        }

    printf("%ld\n", b);
}