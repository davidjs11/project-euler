/*   problem10.c   */

#include <stdio.h>
#include <stdbool.h>

bool is_prime(unsigned int n) {
    if (n < 2) return false;
    if (n == 2) return true;

    for (unsigned int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;

    return true;
}

int main(int argc, char *argv[]) {
    unsigned long result = 0;

    for (unsigned int i = 2; i <= 2000000; i++) {
        if (is_prime(i)) result += i;
    }

    printf("%lu\n", result);

    return 0;
}
