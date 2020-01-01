#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isSameSign(int a, int b);
bool hasFive(int num);
int dontGiveMeFiveStart1(int end);
void swapInts(int *a, int *b);

int dontGiveMeFive(int start, int end) {
    printf("%d %d\n", start, end);
    int res = 0;

    if (abs(start) > abs(end)) {
        swapInts(&start, &end);
    }

    if (!isSameSign(start, end)) {
        // Add 1 to include 0
        res = dontGiveMeFiveStart1(end) + dontGiveMeFiveStart1(start) + 1;
    } else if (isSameSign(start, end)) {
        // Count 1 less to avoid double counting start number
        start -= copysign(1, start);
        res = dontGiveMeFiveStart1(end) - dontGiveMeFiveStart1(start);
    }

    printf("%d\n", res);
    return res;
}

bool isSameSign(int a, int b) {
    if ((a > 0 && b > 0) || (a < 0 && b < 0)) return true;
    else if (a == 0 || b == 0) return false;
    else if ((a > 0 && b < 0) || (a < 0 && b > 0)) return false;

    return false;
}

void swapInts(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

// dontGiveMeFive, but start=1
int dontGiveMeFiveStart1(int end) {
    int sum = abs(end);
    for (int i = 5; i <= abs(end); i++) {
        if (hasFive(i)) sum--;
    }
    printf("%d\n", sum);
    return sum;
}

bool hasFive(int num) {
    // Power if number was written in scientific notation
    unsigned int maxPower = floor(log10(abs(num)));

    // Go from maxPower to 0 (inclusive)
    for (unsigned int p = maxPower + 1; p-- > 0;) {
        int base = pow(10, p);
        int res = (abs(num) + 5 * base) % (10 * base);

        // If res is less than 10^p, pth digit is 5 (right to left)
        // i.e. p=0: 5, p=1:5X, p=2:5XX
        if (abs(res) < base) {
            return true;
        }
    }
    return false;
}

int main() {
    printf("%d", dontGiveMeFive(1, 9));
}
