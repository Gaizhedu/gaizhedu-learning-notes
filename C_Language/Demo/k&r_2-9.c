#include <stdio.h>

int bitcount(unsigned x);

int main() {
    printf("%d",bitcount(1000));
}

int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; ++b) {
        x &= (x - 1);
    }
    return b;
}