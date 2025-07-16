/*   problem09.c   */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_pithagorean_triplet(unsigned int a, unsigned int b, unsigned int c) {
    return (a < b && b < c) && ((a * a) + (b * b) == (c * c));
}

int main(int argc, char *argv[]) {
    unsigned int result = 0;

    for (unsigned int a = 1; a < 1000; a++) {
        for (unsigned int b = 1; b < 1000; b++) {
            unsigned int c = (unsigned int) sqrt((double)(a * a) + (b * b));
            if (a + b + c == 1000 && is_pithagorean_triplet(a, b, c)) {
                result = a * b * c;
                break;
            }
        }
    }

    printf("%u\n", result);

    return 0;
}
