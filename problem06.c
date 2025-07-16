/*   problem06.c   */

#include <stdio.h>
#include <stdbool.h>

bool all_divisors(unsigned int n, unsigned int max_divisor) {
    for (size_t i = 1; i < max_divisor; i++)
        if (n % i) return false;
    return true;
}

int main(int argc, char *argv[]) {
    int result = 0;
    unsigned int sum_of_squares = 0;
    unsigned int square_of_sums = 0;

    for (size_t i = 1; i <= 100; i++) {
        sum_of_squares += i * i;
        square_of_sums += i;
    }
    square_of_sums = square_of_sums * square_of_sums;
    result = sum_of_squares - square_of_sums;
    if (result < 0) result *= -1;

    printf("%d\n", result);

    return 0;
}
