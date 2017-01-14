#include <stdio.h>
//这个题完全没有头绪。。。

#define N 10000

int main() {
	char sci[N];
	gets_s(sci);

	char power_mark;
	int power = 0;
	if (sci[0] == '-')
		printf("-");

	for (int i = 1; i < N; i++) {
		if (sci[i] == 'E') {
			power_mark = sci[i + 1];
			for (int j = i + 2; j < N; j++) {
				if (sci[j])
					power = power * 10 + (sci[j] - '0');
				else
					break;
			}
			break;
		}
	}
	if (power_mark == '-') {
		if (power == 0) {
			for (int i = 1; i < N; i++) {
				if (sci[i] != 'E')
					printf("%c", sci[i]);
				else
					break;
			}
		}
		else {
			for (int i = 0; i < power; i++) {
				printf("0");
				if (i == 0)
					printf(".");
			}
			for (int i = 1; i < N; i++) {
				if (sci[i] != 'E' && sci[i] != '.')
					printf("%c", sci[i]);
				else if (sci[i] == '.')
					continue;
				else
					break;
			}
		}
	}

	if (power_mark == '+') {
		if (power == 0) {
			for (int i = 1; i < N; i++) {
				if (sci[i] != 'E')
					printf("%c", sci[i]);
				else
					break;
			}
		}
		else {
			int fill0flag = 0;
			for (int i = 0; i < power;i++) {
				if (sci[i + 1] != 'E' && sci[i + 1] != '.') {
					printf("%c", sci[i + 1]);
				}
				else if (sci[i + 1] == '.') {
					power++;
				}
				else { //次数还没用完，就到了E说明后面需要补0
					for (int j = i; j < power; j++) 
						printf("0");
					fill0flag = 1;
					break;
				}
			}
			if (!fill0flag) {//说明次数打印完了，还有没输出的小数
				for (int i = power + 1; i < N; i++) {
					if (i == power + 2) {
						printf(".");
					}
					if (sci[i] != 'E')
						printf("%c", sci[i]);
					else break;
				}
			}
		}
	}
	printf("\n");
	return 0;
}