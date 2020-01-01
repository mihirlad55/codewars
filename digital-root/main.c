#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int digital_root(int n) {
    char *num = (char*) malloc(50);
    while (n > 9) {
        sprintf(num, "%d", n);
        int temp = 0;
        for (size_t i = 0; i < strlen(num); i++) {
            temp += num[i] - '0';
        }
        n = temp;
    }
    return n;
}
