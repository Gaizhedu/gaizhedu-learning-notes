#include <stdio.h>

int main() {
	int c, count;

	count = 0;
	while ((c = getchar()) != EOF)
		if (count != 0)
		{
			if (c == ' ')
				++count;
			else
			{
				printf(" %c", c);
				count = 0;
			}
		}
		else
		{
			if (c == ' ')
				++count;
			else
			{
				printf("%c", c);
			}
		}
}