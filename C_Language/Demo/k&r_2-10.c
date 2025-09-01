#include <stdio.h>

int lower();
char to[1000];

int main() {
    lower();
    printf("%s",to);
}

int lower() {
    int c;
    int i = 0;

    while ((c = getchar()) != EOF) {
        c = (c >= 'A' && c <= 'Z') ? c - 'A' + 'a': c;
        to[i] = c;
        ++i;
    }
    to[i] = '\0';
    return 0;
}