/*   problem20.c   */

#include <stdio.h>

#define DIGITS 159
#define N 100

int main(int argc, char *argv[]) {
    unsigned int result = 0;
    unsigned int factor[DIGITS] = {0};
    unsigned int intermediates[DIGITS][DIGITS] = {0};
    unsigned int factorial[DIGITS] = {0};
    unsigned int carry;
    factorial[DIGITS-1] = 1;

    for (size_t n = 0; n < N; n++) {
        /* factor + 1 */
        factor[DIGITS-1] += 1;
        carry = factor[DIGITS-1] / 10;
        factor[DIGITS-1] %= 10;
        for (size_t i = 1; i < DIGITS; i++) {
            factor[DIGITS-i-1] += carry;
            carry = factor[DIGITS-i-1] / 10;
            factor[DIGITS-i-1] %= 10;
        }

        /* factorial * factor */
        for (size_t i = 1; i <= DIGITS; i++)
            for (size_t j = 1; j <= DIGITS; j++)
                intermediates[DIGITS-i][DIGITS-j-i] = factor[DIGITS-i] * factorial[DIGITS-j];

        /* empty old factorial */
        for (size_t i = 1; i <= DIGITS; i++)
            factorial[DIGITS-i] = 0;

        /* sum intermediates */
        carry = 0;
        for (size_t i = 1; i <= DIGITS; i++) {
            for (size_t j = 1; j <= DIGITS; j++) {
                factorial[DIGITS-j] += carry;
                factorial[DIGITS-j] += intermediates[DIGITS-i][DIGITS-j];
                carry = factorial[DIGITS-j] / 10;
                factorial[DIGITS-j] %= 10;
            }
        }

        /* empty intermediate values */
        for (size_t i = 1; i < DIGITS; i++)
            for (size_t j = 1; j < DIGITS; j++)
                intermediates[DIGITS-i][DIGITS-j] = 0;
    }

    
    /* sum digits of factor */
    for (size_t i = 0; i < DIGITS; i++)
        result += factorial[i];

    printf("%u\n", result);
    return 0;
}
