/*   problem12.c   */

#include <stdio.h>

unsigned int count_divisors(unsigned int n) {
    unsigned int result = 0;

    for (size_t i = 2; i*i <= n; i++)
        if (n % i == 0)
            if (i*i == n) result += 1;
            else result += 2;

    return result + 1;
}

int main(int argc, char *argv[]) {
    unsigned long result = 0;
    unsigned long n = 0;

    for (size_t i = 0; result == 0; i++) {
        n = (i * (i+1)) / 2;
        if (count_divisors(n) > 500) result = n;
    }

    printf("%lu\n", result);
    return 0;
}
