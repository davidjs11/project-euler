/*   problem03.c   */

#include <stdio.h>
#include <math.h>

void print_factors(unsigned long n) {
    while (n % 2 == 0) n = n / 2;
    for (unsigned long i = 3; i * i <= n; i += 2)
        if (n % i == 0) n = n / i;
    printf("%d\n", n);
}

int main(int argc, char *argv[]) {
    unsigned int result = 0;

    const unsigned long n = 600851475143;
    print_factors(n);

    printf("%u\n", result);

    return 0;
}
