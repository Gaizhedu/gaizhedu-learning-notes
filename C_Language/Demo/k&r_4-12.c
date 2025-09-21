#include <stdio.h>

#define MAXLINE 100
char s[MAXLINE];
int nums[MAXLINE];
int check_nums = 0;

void itoa(int n[],int lst_nums);

int main() {
    int c,i;

    for (i = 0;(c = getchar()) != EOF;++i,++check_nums) {
        nums[i] = c;
    }
    itoa(nums,0);
    printf("%s",s);
}

void itoa(int n[],int lst_nums) {
    if (lst_nums <= check_nums) {
        s[lst_nums] = n[lst_nums];
        ++lst_nums;
        itoa(nums,lst_nums);
    }
    else {
        s[lst_nums] = '\0';
        return;
    }
}