/*   problem19.c   */

#include <stdio.h>

int main(int argc, char *argv[]) {
    unsigned int result = 0;
    unsigned int total_days = 1;
    unsigned int days = 1;

    for (size_t year = 1901; year <= 2000; year++) {            /* year */
        for (size_t month = 1; month <= 12; month++) {          /* month */
            if (month == 4 || month == 6 || month == 9 || month == 11)
                days = 30;
            else if (month == 2)
                if (year % 4 == 0) {
                    days = 29;
                    if (year % 100 == 0 && year % 400 != 0)
                        days = 28;
                }
                else days = 28;
            else
                days = 31;
            
            for (size_t day = 1; day <= days; day++) {          /* day */
                total_days++;
                if (year >= 1901 && total_days % 7 == 0 && day == 1) {
                    result++;
                    printf("%02d/%02d/%04d\n", day, month, year);
                }
            }

        }
    }

    printf("%u\n", result);
    return 0;
}
