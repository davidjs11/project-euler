/*   problem07.c   */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(unsigned int n) {
    if (n < 2) return false;
    if (n == 2) return true;

    for (unsigned int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;

    return true;
}

int main(int argc, char *argv[]) {
    unsigned int result = is_prime(14);

    for (size_t i = 0, n = 0; n < 10001; i++) {
        if (is_prime(i)) {
            n++;
            result = i;
        }
    }

    printf("%u\n", result);

    return 0;
}
