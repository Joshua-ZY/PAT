#include <stdio.h>

int main() {
	char num1[12], num2[12], D1, D2;
	scanf("%s %c %s %c", num1, &D1, num2, &D2);
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < 12; i++) {
		if (num1[i]) {
			if (num1[i] == D1)
				sum1++;
		}
		else
			break;
	}
	for (int i = 0; i < 12; i++) {
		if (num2[i]) {
			if (num2[i] == D2)
				sum2++;
		}
		else
			break;
	}

	int d1 = D1 - '0';
	int d2 = D2 - '0';
	int p1 = 0, p2 = 0;
	for (int i = 0; i < sum1; i++) {
		p1 = p1 * 10 + d1;
	}
	for (int i = 0; i < sum2; i++) {
		p2 = p2 * 10 + d2;
	}

	printf("%d\n", p1 + p2);

	return 0;
}