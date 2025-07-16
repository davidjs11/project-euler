/*   problem02.c   */

#include <stdio.h>

int fibonacci(unsigned int n) {
    if (n == 0) return 1;
    else if (n == 1) return 2;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char *argv[]) {
    unsigned int result = 0;
    unsigned int fib;

    for (size_t i = 0; fib < 4'000'000; i++) {
        if (fib % 2 == 0) result += fib;
        fib = fibonacci(i);
    }

    printf("%u\n", result);

    return 0;
}
