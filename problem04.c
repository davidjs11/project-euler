/*   problem04.c   */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_palindrome(unsigned int n) {
    char *str = (char *) malloc(16);
    snprintf(str, 16, "%d", n);
    size_t len = strnlen(str, 16);

    for (int i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            free(str);
            return false;
        }
    }

    free(str);
    return true;
}

int main(int argc, char *argv[]) {
    unsigned int result = 0;

    for (size_t a = 100; a < 1000; a++)
        for (size_t b = 100; b < 1000; b++)
            if (is_palindrome(a * b)) 
                if (result < a * b) 
                    result = a * b;

    printf("%u\n", result);

    return 0;
}
