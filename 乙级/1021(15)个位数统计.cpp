#include <stdio.h>

int main() {
	int total[10] = { 0 };
	char num[1001];
	gets_s(num); //提交时要改成gets(num);

	for (int i = 0; i < 1001; i++) {
		if (num[i]) {
			int digit = num[i] - '0';
			total[digit]++;
		}
		else
			break;
	}

	for (int i = 0; i < 10; i++) {
		if (total[i])
			printf("%d:%d\n", i, total[i]);
	}
	return 0;
}