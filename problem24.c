/*   problem24.c   */

/* had to search a solution for this one but i learnt about combinatorics :p */

#include <stdio.h>
#include <math.h>

#define DIGITS 10

unsigned long factorial(unsigned long n) {
    unsigned long result = 1;
    for (size_t i = 1; i <= n; i++)
        result *= i;
    return result;
}

int main(int argc, char *argv[]) {
    unsigned int result = 0;
    unsigned int position = 999999;
    unsigned int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (size_t i = 1; i <= DIGITS; i++) {
        /* calculate digit index and new position */
        size_t digit = position / factorial(DIGITS-i);
        position = position % factorial(DIGITS-i);

        /* print digit */
        printf("%u", digits[digit]);

        /* delete used digit */
        for (size_t j = digit; j < DIGITS-1; j++)
            digits[j] = digits[j+1];
    }
    printf("\n");
    
    return 0;
}
