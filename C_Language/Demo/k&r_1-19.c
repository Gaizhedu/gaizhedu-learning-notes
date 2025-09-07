#include <stdio.h>

char lst[1000];
void reversed(char s[]);

int main() {
    reversed(lst);
}

void reversed(char s[]) {
    int c = 0;
    int i = 0,count = 0;

    while ((c = getchar()) != EOF && i < 999) {
        s[i] = c;
        ++i;
        ++count;
    }
    s[i] = '\0';
    for (i = 0;i < count;++i) {
        int temp = s[i];
        s[i] = s[count - 1];
        s[count - 1] = temp;
        --count;
    }
    printf("%s",s);
}