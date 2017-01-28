#include <stdio.h>

#define MAXSTU 100000

int main() {
	int stunum, score, checknum, scorenum[101] = { 0 };
	scanf("%d", &stunum);
	for (int i = 0; i < stunum; i++) {
		scanf("%d", &score);
		scorenum[score]++;
	}
	scanf("%d", &checknum);
	//第一次输出的前面不用空格
	scanf("%d", &score);
	printf("%d", scorenum[score]);
	//后面每次输出前面空一格
	for (int i = 1; i < checknum; i++) {
		scanf(" %d", &score);
		printf(" %d", scorenum[score]);
	}
	return 0;
}