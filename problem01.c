/*   problem01.c   */

#include <stdio.h>

int main(int argc, char *argv[]) {
    unsigned int result = 0;

    for (size_t i = 0; i < 1000; i++)
        if ((i % 3 == 0) || (i % 5 == 0))
            result += i;

    printf("%u\n", result);

    return 0;
}
