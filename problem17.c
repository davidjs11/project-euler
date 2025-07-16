/*   problem17.c   */

#include <stdio.h>
#include <string.h>
#include <math.h>

size_t name_len(unsigned int n) {
    if (n == 0) return 0;
    else if (n == 1) return strlen("one");
    else if (n == 2) return strlen("two");
    else if (n == 3) return strlen("three");
    else if (n == 4) return strlen("four");
    else if (n == 5) return strlen("five");
    else if (n == 6) return strlen("six");
    else if (n == 7) return strlen("seven");
    else if (n == 8) return strlen("eight");
    else if (n == 9) return strlen("nine");
    else if (n == 10) return strlen("ten");
    else if (n == 11) return strlen("eleven");
    else if (n == 12) return strlen("twelve");
    else if (n == 13) return strlen("thirteen");
    else if (n == 14) return strlen("fourteen");
    else if (n == 15) return strlen("fifteen");
    else if (n == 16) return strlen("sixteen");
    else if (n == 17) return strlen("seventeen");
    else if (n == 18) return strlen("eighteen");
    else if (n == 19) return strlen("nineteen");
    else if (20 <= n && n <= 29) return strlen("twenty") + name_len(n % 10);
    else if (30 <= n && n <= 39) return strlen("thirty") + name_len(n % 10);
    else if (40 <= n && n <= 49) return strlen("forty") + name_len(n % 10);
    else if (50 <= n && n <= 59) return strlen("fifty") + name_len(n % 10);
    else if (60 <= n && n <= 69) return strlen("sixty") + name_len(n % 10);
    else if (70 <= n && n <= 79) return strlen("seventy") + name_len(n % 10);
    else if (80 <= n && n <= 89) return strlen("eighty") + name_len(n % 10);
    else if (90 <= n && n <= 99) return strlen("ninety") + name_len(n % 10);
    if (n >= 100 && n < 1000) {
        unsigned int hundreds = n / 100;
        unsigned int remainder = n % 100;
        size_t len = name_len(hundreds) + strlen("hundred");
        if (remainder != 0)
            len += strlen("and") + name_len(remainder);
        return len;
    }
    else if (n == 1000) return strlen("onethousand");
}

int main(int argc, char *argv[]) {
    unsigned int result = 0;

    for (size_t i = 1; i <= 1000; i++)
        result += name_len(i);

    printf("%u\n", result);
    return 0;
}
