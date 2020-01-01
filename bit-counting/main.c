#include <stdio.h>
#include <stddef.h>

size_t countBits(unsigned int val) {
    size_t count = 0;
    while (val) {
        count += val & 1;
        val >>= 1;
    }
    return count;
}

int main() {
    printf("%zu", countBits(25));
}
