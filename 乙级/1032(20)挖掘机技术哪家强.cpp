#include <stdio.h>
#define MAXSCHOOL 100000

int main() {
	int marks[MAXSCHOOL] = { 0 }, n, school, score;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &school, &score);
		marks[school] += score;
	}

	int maxscore = 0, maxschool;
	for (int i = 0; i < MAXSCHOOL; i++) {
		if (marks[i] > maxscore) {
			maxscore = marks[i];
			maxschool = i;
		}
	}
	printf("%d %d", maxschool, maxscore);
	return 0;
}