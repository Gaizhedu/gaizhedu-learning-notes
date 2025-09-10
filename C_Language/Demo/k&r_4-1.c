#include <stdio.h>

#define MAXLINE 1000
char s[MAXLINE],t[] = "ould";
int max = 0;

int getline1(char s[],int lim);

int strrindex(char s[],char t[]);

int main() {
    while (getline1(s,MAXLINE) > 0) {
        int o = strrindex(s,t);
        if (o > 0) {
            printf("%d",o);
        }
        else
            printf("error");
    }
}

int getline1(char s[],int lim) {
    int c = 0,i = 0;

    while ((c = getchar()) != EOF) {
        s[i++] = c;
    }
    max = i;
    return i;
}

int strrindex(char s[],char t[]) {
    int i,c = 0;

    int k;



    for (;max-- > 0;) {
        int p = max;
        for (k = 0;s[p] == t[k] && t[k] != '\0';++k,++p) {
            ;
        }
        if (t[k] == '\0') {
            return max + 1;
        }
    }
}