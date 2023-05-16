#include <stdio.h>
#include <gmp.h>

int main()
{
    mpz_t sum, pown, count, result;
    mpz_init(sum);

    char *filename = "13.txt";
    char cc[50];
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }
    while ((fgets(cc, 50, fp)) != NULL) {
        mpz_init_set_str(count, cc, 10);
        mpz_add(sum, sum, count);
        mpz_clear(count);
    }

    int len = mpz_sizeinbase(sum, 10);

    for (int i = len, j = len; i > 41; i--, j--) {
        mpz_init(result);
        mpz_init(pown);

        mpz_ui_pow_ui(pown, 10, i);
        mpz_mod(result, sum, pown);

        mpz_clear(pown);
        mpz_init(pown);
        mpz_ui_pow_ui(pown, 10, j-1);

        mpz_tdiv_q(result, result, pown);
        gmp_printf("%Zd", result);
        mpz_clear(result);
    }
    putchar('\n');
    fclose(fp);
}
