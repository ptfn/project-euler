#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#define N 28123

bool excess[N];
bool pair_sum[N];

bool exc_div(uint16_t number)
{
    uint32_t result = 1;
    for (uint16_t i = 2; i <= sqrt(number); i++)
        if (number % i == 0)
            if (i != sqrt(number))
                result += i + (number / i); 
            else
                result += i;
    return result > number;
}

void fill_zero(bool array[], uint16_t length)
{
    for (uint16_t i = 0; i < length; i++)
        array[i] = false;
}

int main()
{
    fill_zero(excess, N);
    fill_zero(pair_sum, N);

    for (uint16_t i = 0; i < N; i++)
        excess[i] = exc_div(i+1);

    for (uint16_t i = 0; i < N; i++)
        for (uint16_t j = 0; j < N; j++)
            if (excess[i] && excess[j] && i+j+2 < N)
                pair_sum[i+j+2] = true;
    
    uint32_t sum = 0;
    for (uint16_t i = 0; i < N; i++)
        if (!(pair_sum[i]))
            sum += i;
    printf("%d\n", sum);
    return 0;
}