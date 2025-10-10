#define MAXLINE 1000
void strcat(char *s,const char *t);

int main() {
    char ls[MAXLINE] = "123";
    char lt[MAXLINE] = "456";
    char *ps = ls;
    char *pt = lt;
    strcat(ps,pt);
    printf("%s",ps);
    return 0;
}

void strcat(char *s,const char *t) {
    for (;*s != '\0';++s) {
        ;
    }
    for (;*t != '\0';++s,++t) {
        *s = *t;
    }
    *s = '\0';
}