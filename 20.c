#include <stdint.h>
#include <stdio.h>
#include <gmp.h>
#define N 100

int main()
{
    mpz_t power, number, result, auxiliary;
    mpz_init_set_ui(number, 1);
    mpz_init(result);

    for (uint8_t i = 1; i <= N; i++)
        mpz_mul_ui(number, number, i);

    for (uint8_t i = 1; i <= mpz_sizeinbase(number, 10); i++) {
        mpz_init(auxiliary);
        mpz_init(power);

        mpz_ui_pow_ui(power, 10, i);
        mpz_mod(auxiliary, number, power);

        mpz_clear(power);
        mpz_init(power);
        mpz_ui_pow_ui(power, 10, i-1);

        mpz_tdiv_q(auxiliary, auxiliary, power);
        mpz_add(result, result, auxiliary);
        mpz_clear(auxiliary);
    }

    gmp_printf("%Zd\n", result);
}