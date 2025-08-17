#include <stdio.h>

int main() {
	int c, ns, nl, nt;

	nl = 0;
	ns = 0;
	nt = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++ns;
		else if (c == '\n')
			++nl;
		else if (c == '\t')
			++nt;
	}
	printf("你的输入中有%d个空格，%d个换行符，%d个制表符", ns, nl, nt);
}