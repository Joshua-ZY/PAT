#include <stdio.h>

#define MAXCHAR 100001

void numto01(int num, int ans[]) {//ans的初始值是0,0
	while (num > 0) {
		ans[num % 2]++;
		num /= 2;
	}
}

int main() {
	char arr[MAXCHAR];
	int sum = 0;
	gets_s(arr);
	for (int i = 0; i < MAXCHAR; i++) {
		if (arr[i]) {
			if (arr[i] >= 'a' && arr[i] <= 'z')
				sum += arr[i] - 'a' + 1; //认为序号从1开始
			else if (arr[i] >= 'A' && arr[i] <= 'Z')
				sum += arr[i] - 'A' + 1;
		}
		else
			break;
	}
	int ans[2] = { 0 };
	numto01(sum, ans);
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}