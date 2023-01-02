#include <stdint.h>
#include <stdio.h>
#define N 20
#define M 20

uint64_t arr[N+1][M+1];

uint64_t route(uint8_t x, uint8_t y)
{
    if (arr[x][y] == 0)
        if (x == 0)
            arr[x][y] = route(x, y - 1);
        else if (y == 0)
            arr[x][y] = route(x - 1, y);
        else
            arr[x][y] = route(x - 1, y) + route(x, y - 1);
    return arr[x][y];
    
}

int main()
{
    for (uint8_t i = 0; i <N; i++)
        for (uint8_t j = 0; j < M; j++)
            arr[i][j] = 0;

    arr[1][0] = 1;
    arr[0][1] = 1;
    
    printf("%ld\n", route(20, 20));
    return 0;
}