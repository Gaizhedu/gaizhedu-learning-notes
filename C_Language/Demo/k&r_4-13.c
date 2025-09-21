#include <stdio.h>

#define MAXLINE 1000
char string[] = "Helloworld!";
int ptr = 0;
int nums = 0;
int lst_nums = 0;

void reverse(char s[]);

int main() {
    int i;

    for (i = 0;string[i] != '\0';++i, ++ptr) {
        ;
    }
    nums = ptr - 1;
    reverse(string);
    printf("%s",string);
}

void reverse(char s[]) {
    char temp;

    int line = (ptr / 2);
    if (lst_nums <= line) {
        temp = s[nums];
        s[nums--] = s[lst_nums];
        s[lst_nums++] = temp;
        reverse(s);
    }
}