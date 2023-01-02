#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define F(n, i) (int)(n / pow(10, i)) % 10

int lennum(int n) {
  int r = 1;
  while ((n /= 10) != 0) 
    r++;
  return r;
}

bool ispalidrom(int n)
{
    int m = lennum(n);
    for (int i = 0; i < m/2; i++)
        if (F(n, i) != F(n, m-1-i))
            return false;
    return true;
}

int main()
{
    int max = 0;
    for (int i = 100; i <= 999; i++)
        for (int j = 100; j <= 999; j++)
            if (ispalidrom(j*i))
                if (max < (j*i))
                    max = j*i;
    printf("%d\n", max);
}