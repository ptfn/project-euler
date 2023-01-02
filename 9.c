#include <stdint.h>
#include <stdio.h>
#include <math.h>
#define N 1000

int main()
{
    uint16_t i, j, k;
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
            for (k = 1; k <= N; k++)
                if (sqrt(pow(i, 2) + pow(j, 2)) == k)
                    if (i + j + k == N) {
                        printf("%d\t%d\t%d\t%d\n", i*j*k, i, j, k);
                        return 0;
                    }
}