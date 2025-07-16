/*   problem16.c   */

#include <stdio.h>

#define EXPONENT 1000
#define DIGITS 350

int main(int argc, char *argv[]) {
    unsigned int result = 0;
    unsigned long carry = 0;
    unsigned int power[DIGITS] = {0};
    power[DIGITS-1] = 1;

    for (size_t j = 0; j < EXPONENT; j++) {
        carry = 0;
        power[DIGITS - 1] *= 2;
        carry = power[DIGITS - 1] / 10;
        power[DIGITS - 1] %= 10;

        for (size_t i = 1; i < DIGITS; i++) {
            power[DIGITS - i - 1] *= 2;
            power[DIGITS - i - 1] += carry;
            carry = power[DIGITS - i - 1] / 10;
            power[DIGITS - i - 1] %= 10;
        }
    }

    for (size_t i = 0; i < DIGITS; i++)
        result += power[i];

    printf("%u\n", result);
    return 0;
}
