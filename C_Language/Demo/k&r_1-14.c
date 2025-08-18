#include <stdio.h>

int main() {
	int c, i;
	int n_cs[62],n_co[62];
	
	for (i = 0; i < 62; ++i)
		n_cs[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++n_cs[c - '0'];
		}
		else if (c >= 'a' && c <= 'z') {
			++n_cs[c - 'a' + 10];
		}
		else if (c >= 'A' && c <= 'Z') {
			++n_cs[c - 'A' + 36];
		}
	}
	for(i = 0;i < 62;++i)
		printf("%d",n_cs[i]);
}