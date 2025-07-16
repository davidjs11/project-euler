/*   problem22.c   */

#include <stdio.h>
#include <string.h>

#define STRING_SIZE 32
char names[][STRING_SIZE] = {
#include "data/0022_names.txt"
,"EOF"
};

int main(int argc, char *argv[]) {
    unsigned long result = 0;
    unsigned int len = 0;
    char temp[STRING_SIZE];

    /* get number of names */
    for (size_t i = 0; strncmp(names[i], "EOF", 3UL); i++)
        len++;

    /* bubble sort */
    for (size_t i = 0; i < len-1; i++) {
        for (size_t j = 0; j < len-i-1; j++) {
            if (strncmp(names[j], names[j+1], STRING_SIZE) > 0) {
                strncpy(temp, names[j+1], STRING_SIZE);
                strncpy(names[j+1], names[j], STRING_SIZE);
                strncpy(names[j], temp, STRING_SIZE);
            }
        }
    }

    /* count name value and multiply by index */
    for (size_t i = 0; i < len; i++) {
        size_t name_value = 0;
        for (size_t j = 0; j < strlen(names[i]); j++)
            name_value += names[i][j] - 'A' + 1;
        result += (i+1) * name_value;
    }

    printf("%lu\n", result);
    return 0;
}
