/*   problem23.c   */

/* ngl this one fried my brain a bit */

#include <stdio.h>
#include <stdbool.h>

bool abundants[28123] = {false};
unsigned int last_checked = 0;

bool abundant(unsigned int n) {
    if (n > last_checked) {
        unsigned int sum = 0;
        for (size_t i = 1; i < n; i++)
            if (n % i == 0)
                sum += i;

        last_checked = n;
        abundants[n] = (sum > n);
    }

    return abundants[n];
}

bool can_be_sum(unsigned int n) {
    for (size_t i = 1; i <= n / 2; i++) {
        size_t j = n - i;
        if (i + j == n && abundant(i) && abundant(j))
            return true;
    }

    return false;
}

int main(int argc, char *argv[]) {
    unsigned int result = 0;
    unsigned int limit = 28123;

    for (size_t num = 0; num <= 28123; num++) {
        if (!can_be_sum(num))
            result += num;
    }

    printf("%u\n", result);
    return 0;
}
