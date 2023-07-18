#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#define N   5171
#define M   30
#define L   16

void swap(char *str1, char *str2)
{
    char temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void sort(char arr[M][M])
{
    for (uint16_t i = 0; i < N-1; i++)
        for (uint16_t j = 0; j < N-i-1; j++)
            if (strcmp(arr[j], arr[j+1]) > 0)
                for (uint8_t k = 0; k < M; k++)
                    swap(&arr[j][k], &arr[j+1][k]);
}

int main()
{
    char *filename = "22.txt", arr[N][M], buffer[L];
    bool status = false;
    uint16_t n = 0, m = 0;
    FILE *fp;

    for (uint16_t i = 0; i < N; i++)
        for (uint16_t j = 0; j < M; j++)
            arr[i][j] = 0;

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }

    while ((fgets(buffer, L, fp)) != NULL)
        for (uint8_t j = 0; j < L; j++)
            if (buffer[j] == '"')
                if (status) {
                    status = false;
                    n++;
                    m = 0;
                } else
                 status = true;
            else if (status)
                arr[n][m++] = buffer[j];

    sort(arr);
    
    for (uint16_t i = 0; i < N; i++) {
        for (uint16_t j = 0; j < M; j++)
            if (arr[i][j] >= 'A' && arr[i][j] <= 'Z')
                putchar(arr[i][j]);
        putchar(' ');
    }
    putchar('\n');

    return 0;
} 