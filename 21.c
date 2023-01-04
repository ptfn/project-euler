#include <stdint.h>
#include <stdio.h>
#define N 10000

uint16_t sum_div(uint16_t number)
{
    uint16_t result = 0;
    for (uint16_t i = 1; i < number; i++)
        if (number % i == 0)
            result += i;
    return result;
}

int main()
{
    uint32_t result = 0, t;
    for (uint16_t i = 1; i < N; i++)
        if (i == sum_div((t = sum_div(i))) && i != t)
            result += i;
            
    printf("%d\n", result);
    return 0;
}