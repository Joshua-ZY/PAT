#include <stdio.h>

int main() {
	char num[1001], ans[1001];
	int dev;
	scanf("%s %d", num, &dev);

	int anspos = 0, first_flag = 1, oneans, remain = 0;
	for (int i = 0; i < 1001; i++) {
		if (num[i]) {
			oneans = (10 * remain + (num[i] - '0')) / dev;
			remain = (10 * remain + (num[i] - '0')) % dev;
			if (oneans == 0 && first_flag)
				continue;
			else {
				ans[anspos] = oneans + '0';
				anspos++;
				first_flag = 0;
			}
		}
		else
			break;
	}
	if (first_flag) {  //说明结果为0
		ans[anspos] = '0';
		anspos++;
	}
	ans[anspos] = '\0';
	printf("%s %d", ans, remain);
	return 0;
}