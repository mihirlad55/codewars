#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

char* likes(size_t n, const char *const names[n]) {
    char *out = (char *) malloc(100);

    if (n == 0) {
        strcpy(out, "no one likes this");
    } else if (n >= 1) {
        strcpy(out, names[0]);

        if (n == 1) {
            strcat(out, " likes this");
        } else if (n >= 2) {
            if (n == 2) {
                strcat(out, " and ");
                strcat(out, names[1]);
                strcat(out, " like this");
            } else if (n == 3) {
                strcat(out, ", ");
                strcat(out, names[1]);
                strcat(out, " and ");
                strcat(out, names[2]);
                strcat(out, " like this");
            }
            else if (n >= 4) {
                strcat(out, ", ");
                strcat(out, names[1]);
                strcat(out, " and ");
                char num[30];
                sprintf(num, "%zu", n-2);
                strcat(out, num);
                strcat(out, " others like this");
            }
        }
    }
    return out;
}
