#include <stdio.h>
#include <gmp.h>
#define N 1000

int main()
{
    unsigned long i = 2;
    mpz_t a, b, c;
    mpz_init(c);
    mpz_init_set_ui(a, 1);
    mpz_init_set_ui(b, 1);

    while (mpz_sizeinbase(b, 10) < N) {
        mpz_add(c, a, b);
        mpz_init_set(a, b);
        mpz_init_set(b, c);
        i++;
    }
    gmp_printf("%Zd\n", b);
    printf("%ld\n", ++i);

    return 0;
}
