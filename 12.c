#include <stdint.h>
#include <stdio.h>
#include <math.h>

#define N 500

uint32_t divider(uint64_t number)
{
    uint32_t result = 1, i = 2;
    for (i; i*i <= number; i++)
        if (number % i == 0)
            result++;
    
    if (sqrt(number) == (int)sqrt(number)) 
        return 2 * result - 1;
    return 2 * result; 
}

int main()
{
    uint64_t sum = 1, i = 1;

    while (1) 
        if (divider(sum += ++i) >= N)
            break;
    printf("%ld\n", sum);
}