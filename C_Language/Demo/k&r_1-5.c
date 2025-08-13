#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 150
int main() {
	float fahr;
	for (fahr = UPPER; fahr >= 0; fahr -= STEP) {
		printf("%3.1f\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
	}
}