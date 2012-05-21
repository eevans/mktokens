
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char *argv[]) {
    int i = 0, num_arg = 0;
    mpz_t max, unit, num, token;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <num_tokens>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (1 != sscanf(argv[1], "%d", &num_arg)) {
        fprintf(stderr, "Cannot parse %s as number of tokens.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    mpz_init(max);
    mpz_init(unit);
    mpz_init(num);
    mpz_init(token);

    mpz_set_ui(num, num_arg);
    mpz_set_ui(token, 0);    // start at token 0

    mpz_ui_pow_ui(max, 2, (128-1));
    mpz_tdiv_q(unit, max, num);

    for (; i < num_arg; i++) {
        gmp_printf("%Zd\n", token);
        mpz_add(token, token, unit);
    }
    
    return 0;
}
