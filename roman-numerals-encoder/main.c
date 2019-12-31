#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strCatMultiple(char* dest, char ch, int mul);

char *solution(int n) {
    const int I = 1;
    const int V = 5;
    const int X = 10;
    const int L = 50;
    const int C = 100;
    const int D = 500;
    const int M = 1000;

    char *out = (char *) calloc(1, sizeof((char)*out));

    int numOfM = n / M;
    n = n % M;
    strCatMultiple(out, 'M', numOfM);
    if (n / C == 9) {
        // Subtractive case
        strcat(out, "CM");
        n -= 9 * C;
    }

    int numOfD = n / D;
    n = n % D;
    strCatMultiple(out, 'D', numOfD);
    if (n / C == 4) {
        strcat(out, "CD");
        n -= 4 * C;
    }

    int numOfC = n / C;
    n = n % C;
    strCatMultiple(out, 'C', numOfC);
    if (n / X == 9) {
        strcat(out, "XC");
        n -= 9 * X;
    }

    int numOfL = n / L;
    n = n % L;
    strCatMultiple(out, 'L', numOfL);
    if (n / X == 4) {
        strcat(out, "XL");
        n -= 4 * X;
    }

    int numOfX = n / X;
    n = n % X;
    strCatMultiple(out, 'X', numOfX);
    if (n / I == 9) {
        strcat(out, "IX");
        n -= 9 * I;
    }

    int numOfV = n / V;
    n = n % V;
    strCatMultiple(out, 'V', numOfV);
    if (n / I == 4) {
        strcat(out, "IV");
        n -= 4 * I;
    }

    int numOfI = n / I;
    n = n % I;
    strCatMultiple(out, 'I', numOfI);

    return out;
}


void strCatMultiple(char* dest, char ch, int mul) {
    int len = strlen(dest);

    memset(dest + len, ch, mul);
    dest[len + mul] = '\0';
}

int main() {
    char line[256];
    int n = 0;

    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%d", &n)) {
            printf("%s\n", solution(n));
        }
    }

}
