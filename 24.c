#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define N 1000000
#define LENGTH 10
char result[LENGTH];
char arr[LENGTH] = {'0', '1', '2', '3', '4',
                    '5', '6', '7', '8', '9'};

uint64_t fact(uint8_t number)
{
    uint64_t result = 1;
    for (uint8_t i = 1; i <= number; result *= i, i++);
    return result;
}

void del_item(char arr[], uint8_t size, uint8_t index)
{
    for (uint8_t i = 0; i < size-1; i++)
        if (i >= index)
            arr[i] = arr[i+1];
}

int main()
{
    for (uint32_t i = 1; i < N; i++) {
        char copy[LENGTH];
        strcpy(copy, arr);
        for (uint8_t j = LENGTH; j > 0; j--) {
            uint8_t index = i / fact(j-1) % j;
            result[j] = copy[index];
            del_item(copy, LENGTH, index);
        }
    }
    
    for (uint8_t i = LENGTH; i > 0; i--)
        putchar(result[i]);
    putchar('\n');
    return 0;
}