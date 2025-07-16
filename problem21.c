/*   problem21.c   */

#include <stdio.h>

unsigned int d(unsigned int n) {
    unsigned int result = 0;

    for (size_t i = 1; i < n; i++)
        if (n % i == 0)
            result += i;

    return result;
}

int main(int argc, char *argv[]) {
    unsigned int result = 0;
    unsigned int a = 0;

    for (size_t i = 0; i < 10000; i++) {
        a = d(i);
        if (d(a) == i && d(i) == a && i != a)
            result += i + a;
    }
    result /= 2;

    printf("%u\n", result);
    return 0;
}
