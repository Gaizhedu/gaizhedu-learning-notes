#include <stdio.h>

int main() {
	int c,i;
	int n_digit[10];

	for (i = 0; i < 10; ++i)
	{
		n_digit[i] = 0;
 	}
	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++n_digit[c - '0'];
		}
	}
	for (i = 0; i < 10; ++i) {
		printf("\n%d：%d",i, n_digit[i]);
	}
}