#include <stdio.h>

int main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;

	printf("华氏温度转换器");
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("华氏度：%3.1f\t摄氏度：%6.1f\n", fahr, celsius);
		fahr += 150;
	}
}