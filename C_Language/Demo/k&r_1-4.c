#include <stdio.h>

int main() {
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	celsius = lower;

	printf("摄氏温度转换器");
	while (celsius <= upper) {
		fahr = celsius * (9.0 / 5.0) + 32.0;
		printf("摄氏度：%3.1f\t华氏度：%6.1f\n",celsius, fahr);
		celsius += 150;
	}
}