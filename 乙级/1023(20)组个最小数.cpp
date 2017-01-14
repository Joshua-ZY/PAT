#include <stdio.h>

int main() {
	int digits[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &digits[i]);
	}
	for (int i = 1; i < 10; i++) { //略过0，找第一个出现次数不为0的数字
		if (digits[i]) {
			printf("%d", i);
			digits[i]--;
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < digits[i]; j++) {
			printf("%d", i);
		}
	}
	printf("\n");
	return 0;
}