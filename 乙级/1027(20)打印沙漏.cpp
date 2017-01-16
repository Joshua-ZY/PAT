#include <stdio.h>

int main() {
	int num;
	char mark;
	scanf("%d %c", &num, &mark);
	int i = 3, sum = 1;
	while (sum + 2*i <= num) {
		sum += 2 * i;
		i += 2;
	}
	i -= 2;//i是最多的一行的符号个数，也是打印的总行数
	//打印上面的部分
	for (int j = 0; j < i / 2; j++) {
		for (int m = 0; m < j; m++)
			printf(" ");
		for (int m = 0; m < i - 2 * j; m++)
			printf("%c", mark);
		printf("\n");
	}
	//打印中间一行
	for (int m = 0; m < i / 2; m++)
		printf(" ");
	printf("%c\n", mark);
	//打印下面的部分
	for (int j = i / 2 - 1; j >= 0; j--) {
		for (int m = 0; m < j; m++)
			printf(" ");
		for (int m = 0; m < i - 2 * j; m++)
			printf("%c", mark);
		printf("\n");
	}
	printf("%d\n", num - sum);
	return 0;
}