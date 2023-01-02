#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#define N 1000

char *number1[] = {"one", "two", "three", "four", "five", "six",
                  "seven", "eight", "nine", "ten", "eleven", "twelve",
                  "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                  "eighteen", "nineteen"};

char *number2[] = {"twenty", "thirty", "forty", "fifty",
                   "sixty", "seventy", "eighty", "ninety"};

char* concat(char *s1, char *s2)
{
        size_t len1 = strlen(s1);
        size_t len2 = strlen(s2);                      
        char *result = malloc(len1 + len2 + 1);
        if (!result) {
            fprintf(stderr, "malloc() failed: insufficient memory!\n");
            return NULL;
        }
        memcpy(result, s1, len1);
        memcpy(result + len1, s2, len2 + 1);    
        return result;
}

uint16_t F(uint16_t n, uint16_t i) 
{
    return (int)(n % (int)pow(10, i) / pow(10, i-1));
}

int main()
{
    char *words[N];
    uint16_t len = 0;

    for (uint16_t i = 1; i <= N; i++) {
        if (i < 20)
            words[i-1] = number1[i-1];
        else if (i < 100) {
            if (i%10 == 0) {
                uint16_t m = (F(i, 2)-2) % 8;
                words[i-1] = number2[m];
            }
            else {
                uint16_t j = (F(i, 2)-2) % 8, k = (F(i, 1)-1) % 9;
                words[i-1] = concat(number2[j], number1[k]);
            }

        }
        else if (i < 1000) {
            uint16_t j = F(i, 3)-1, l = i % 100;
            char *hundred = concat(number1[j], "hundred");
            if (l < 1)
                words[i-1] = hundred;
            else if (l < 10)
                words[i-1] = concat(hundred, concat("and", number1[l-1]));
            else if (l < 20)
                words[i-1] = concat(hundred, concat("and", number1[l-1]));
            else if (l < 100) {
                if (l%10 == 0) {
                    uint16_t m = (F(l, 2)-2) % 8;
                    words[i-1] = concat(hundred, concat("and", number2[m]));
                }
                else {
                    uint16_t j = (F(l, 2)-2) % 8, k = (F(l, 1)-1) % 9;
                    words[i-1] = concat(hundred, concat("and", concat(number2[j], number1[k])));
                }

            }
        }
        else
            words[i-1] = "onethousand";
    }

    for (uint16_t i = 0; i < N; i++) {
        len += strlen(words[i]);
        printf("%d\t%s -> %ld\n", i+1, words[i], strlen(words[i]));
    }
    
    printf("%d\n", len);

    return 0;
}
