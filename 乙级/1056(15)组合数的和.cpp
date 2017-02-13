#include <stdio.h>

int combine(int a, int b) {
	return a * 10 + b;
}

int main() {
	int num, digit[10], sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", &digit[i]);

	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			sum += combine(digit[i], digit[j]) + combine(digit[j], digit[i]);
		}
	}
	printf("%d\n", sum);
	return 0;
}