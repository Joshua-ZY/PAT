#include <stdio.h>
#define MAXDAY 100010
int dist[MAXDAY] = { 0 };

int main() {
	int day;
	scanf("%d", &day);
	for (int i = 0; i < day; i++)
		scanf("%d", &dist[i]);
	int lowdist = 0, highdist = MAXDAY;

	//为了加速，运用了二分法查找
	while (1) {
		int daysum = 0, middist = (lowdist + highdist) / 2;
		for (int i = 0; i < day; i++) {
			if (dist[i] > middist) { //注意题目中是超过！不能相等
				daysum++;
				if (daysum >= middist)
					break;
			}
		}
		if (daysum >= middist) {
			lowdist = middist;
		}
		else if (daysum < middist) {
			highdist = middist - 1;
		}

		if (highdist <= lowdist) {
			printf("%d\n", lowdist);
			return 0;
		}
		else if (highdist - lowdist <= 1) {
			int uppercount = 0;
			for (int i = 0; i < day; i++) {
				if (dist[i] > highdist) {
					uppercount++;
					if (uppercount >= highdist) {
						printf("%d\n", highdist);
						return 0;
					}
				}
			}
			printf("%d\n", lowdist);
			return 0;
		}
	}
}