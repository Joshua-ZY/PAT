#include <stdio.h>

int main() {
	int A, B, D, sum;
	scanf("%d%d%d", &A, &B, &D);
	sum = A + B;
	
	//除D取余法]
	int remain = 0, pos = 0;
	char ans[50];
	if (sum == 0)
		printf("0");
	while (sum != 0) {
		remain = sum % D;
		sum /= D;
		ans[pos] = remain + '0';
		pos++;
	}
	//要将ans倒着输出
	for (int i = pos - 1; i >= 0; i--) {
		printf("%c", ans[i]);
	}
	printf("\n");
	return 0;
}