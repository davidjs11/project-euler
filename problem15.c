/*   problem15.c   */

/* had to search a bit for this problem :-( */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 20

int main(int argc, char *argv[]) {
    unsigned __int128 result = 1;

    for (unsigned long i = SIZE+1; i <= 2*SIZE; i++)
        result *= i;

    for (unsigned long i = 2; i <= SIZE; i++)
        result /= i;

    printf("%lu\n", result);
    return 0;
}
