/*   problem05.c   */

#include <stdio.h>
#include <stdbool.h>

bool all_divisors(unsigned int n, unsigned int max_divisor) {
    for (size_t i = 1; i < max_divisor; i++)
        if (n % i) return false;
    return true;
}

int main(int argc, char *argv[]) {
    unsigned int result = 0;

    for (size_t i = 1; result == 0; i++)
        if (all_divisors(i, 20)) result = i;

    printf("%u\n", result);

    return 0;
}
