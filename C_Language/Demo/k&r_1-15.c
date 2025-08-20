// 注意：书中原练习为用函数实现转换华氏度转换摄氏度
// 此处为了符合使用习惯将两者倒换，但核心框架不变
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 150
float ctof(float);

int main() {
	float c;
	
	c = LOWER;
	for (c = 0; c <= UPPER; c += STEP) {
		printf("输入的摄氏度：%3.1f ，输出的华氏度：%6.1f\n", c, ctof(c));
	}
	return 0;
}

float ctof(float celsius) {
	return celsius * (9.0 / 5.0) + 32.0;
}