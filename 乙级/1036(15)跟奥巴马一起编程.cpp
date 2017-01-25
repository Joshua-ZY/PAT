#include <stdio.h>

int main() {
	int num, row;
	char ca;
	scanf("%d %c", &num, &ca);
	//输出上边
	for (int i = 0; i < num; i++)
		printf("%c", ca);
	printf("\n");
	//输出左右边
	row = (float)num / 2 + 0.5;
	for (int i = 0; i < row - 2; i++) {
		printf("%c", ca);
		for (int i = 0; i < num - 2; i++)
			printf(" ");
		printf("%c\n", ca);
	}
	//输出下边
	for (int i = 0; i < num; i++)
		printf("%c", ca);
	printf("\n");
	return 0;
}