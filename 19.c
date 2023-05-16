#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define LEAP(y) (y % 4 == 0 && y % 100 != 0 || y % 400 == 0 ? true : false) 
#define FROM    1901
#define TO      2000

uint8_t MONTH[] = {31, 28, 31, 30,
                   31, 30, 31, 31,
                   30, 31, 30, 31};

bool isunday(uint8_t day, uint8_t month, uint16_t year)
{
    uint32_t number_day = 0;
    MONTH[1] = LEAP(year) ? 29 : 28;

    for (uint16_t i = 1900; i < year; i++)
        number_day += LEAP(i) ? 366 : 365;

    for (uint16_t i = 0; i < month-1; i++)
        number_day += MONTH[i];

    return (number_day += day - 1) % 7 == 6 ? true : false;
}

int main()
{
    uint16_t result = 0; 

    for (uint16_t i = FROM; i <= TO; i++)
        for (uint8_t j = 1; j <= 12; j++)
            if (isunday(1, j, i))
                result++;

    printf("%d\n", result);
    return 0;
}