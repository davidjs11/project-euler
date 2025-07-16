/*   problem25.c   */

#include <stdio.h>
#include <string.h>

#define DIGITS 1001

unsigned int count_digits(unsigned int n[DIGITS]) {
    unsigned int result = 0;

    while (n[result] == 0 && result < DIGITS) result++;

    return DIGITS-result;
}

int main(int argc, char *argv[]) {
    unsigned int result = 0;
    unsigned int carry = 0;
    unsigned int a[DIGITS] = {0};
    unsigned int b[DIGITS] = {0};
    unsigned int c[DIGITS] = {0};
    a[DIGITS-1] = 1;
    b[DIGITS-1] = 1;

    result = 2; /* index */
    for (size_t j = 0; count_digits(c) < 1000; j++) {

        /* c = a + b */
        carry = 0;
        for (size_t i = 1; i <= DIGITS; i++) {
            c[DIGITS - i] = a[DIGITS - i] + b[DIGITS - i] + carry;
            carry = c[DIGITS - i] / 10;
            c[DIGITS - i] %= 10;

        }
        /* b -> a && c -> b */
        memcpy(a, b, DIGITS*sizeof(unsigned int));
        memcpy(b, c, DIGITS*sizeof(unsigned int));

        /* index */
        result++;
    }

    printf("%u\n", result);
    return 0;
}
