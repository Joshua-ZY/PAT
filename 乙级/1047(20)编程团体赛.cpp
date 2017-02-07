#include <stdio.h>

#define MAXTEAM 1000

int main() {
	int num,  teamscore[MAXTEAM] = { 0 }, score, teamnum, membernum;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d-%d%d", &teamnum, &membernum, &score);
		teamscore[teamnum] += score;
	}
	int maxscore = 0, maxteam;
	for (int i = 0; i < MAXTEAM; i++) {
		if (teamscore[i] > maxscore) {
			maxscore = teamscore[i];
			maxteam = i;
		}
	}
	printf("%d %d\n", maxteam, maxscore);
	return 0;
}