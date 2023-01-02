#include <stdio.h>
#include <math.h>

#define N 100

int main()
{
    int res1 = 0, res2 = 0;
    for (int i = 1; i <= N; i++) {
        res1 += pow(i, 2);
        res2 += i;
    }
    printf("%.0f\n", pow(res2, 2) - res1);
}