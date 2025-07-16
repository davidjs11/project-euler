/*   problem14.c   */

#include <stdio.h>
#include <stdlib.h>

unsigned long sequence_longitude(unsigned long n) {
    if (n <= 1) return 1;
    else if (n % 2 == 0) return sequence_longitude(n / 2) + 1;
    else return sequence_longitude(3*n + 1) + 1;
}

int main(int argc, char *argv[]) {
    unsigned long result = 0;

    for (size_t i = 1; i < 1'000'000; i++)
        if (sequence_longitude(result) < sequence_longitude(i)) 
            result = i;

    printf("%lu\n", result);
    return 0;
}
