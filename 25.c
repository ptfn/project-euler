#include <stdint.h>
#include <stdio.h>
#include <gmp.h>
#define N 1000

int main()
{
    mpz_t a, b, c;
    mpz_init(c);
    mpz_init_set_ui(a, 1);
    mpz_init_set_ui(b, 1);

    while (mpz_sizeinbase(b, 10) < 1000) {
        mpz_add(c, a, b);
        mpz_init_set(a, b);
        mpz_init_set(b, c);
    }
    gmp_printf("%Zd\n", b);
    
    return 0;
}