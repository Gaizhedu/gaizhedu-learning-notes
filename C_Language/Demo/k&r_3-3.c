#define MAXLINE 1000
// reme的作用为记录所有 - 的位置
char s[] = "a-f",s2[MAXLINE];
int expand(char s1[],char s2[]);


int main() {
    expand(s,s2);
    printf("%s",s2);
}

int expand(char s1[],char s2[]) {
    int j, o = 0;
    for (int i = 0; s1[i] != '\0'; ++i) {
        if (s1[i] != '-' || i == 0 || s1[i + 1] == '\0') {
            s2[o] = s1[i];
            ++o;
        }
        else {
            for (j = 0;j < s1[i + 1] - s1[i - 1] - 1;++j,++o) {
                s2[o] = (char)(s1[i - 1] + 1 + j);
            }
        }
    }
}