#include <stdio.h>

int main() {
    int c = 0;

    while ((c = getchar()) != EOF)
        switch (c) {
            case '\t':
                printf("\\t");
                break;
            case '\n':
                printf("\\n");
                break;
            case '\b':
                printf("\\b");
                break;
            default:
                printf("%c",c);
                break;
        }
}