#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dontGiveMeFiveStart1(int end);
int numOf5s(int n, unsigned int power);

int dontGiveMeFive(int start, int end) {
    printf("%d %d\n", start, end);
    return dontGiveMeFiveStart1(end) - dontGiveMeFiveStart1(start - 1);
}

int dontGiveMeFiveStart1(int end) {
    unsigned int maxPower = ceil(log10(abs(end)));
    int sum = end;

    for (unsigned int i = 0; i < maxPower; i++) {
        printf("%u %d = %d\n", i, end, numOf5s(end, i));
        sum -= numOf5s(end, i);
    }
    return sum;
}

int numOf5s(int n, unsigned int power) {
    int base = pow(10, power);
    // If base == 1, mult = 1
    int mult = (power != 0) ? (base * 9.0 / 10.0) : 1.0;
    return mult * floor( (n + 5.0 * base) / (10.0 * base) );
}

int main() {
    printf("%d", dontGiveMeFive(-14, -6));
}
