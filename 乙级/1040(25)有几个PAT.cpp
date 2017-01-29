#include <stdio.h>

#define MAXLEN 100001

int main() {
	char pats[100001];
	gets_s(pats);

	/*countP统计目前P的个数，countPA统计目前有效的PA个数，countPAT统计目前有效的PAT个数
	countP肯定不会超过int的范围，countPA有可能超过，countPAT更有可能。由于countPAT每次都
	加上countPA，所以countPAT的结果模一个数，那么countPA的结果也模这个数，不会影响到PAT的结果。*/
	int countP = 0, countPA = 0, countPAT = 0;
	for (int i = 0; i < MAXLEN; i++) {
		if (pats[i]) {
			if (pats[i] == 'P')
				countP++;
			else if (pats[i] == 'A') {
				countPA += countP;
				if (countPA >= 1000000007)
					countPA %= 1000000007;
			}
			else if (pats[i] == 'T') {
				countPAT += countPA;
				if (countPAT >= 1000000007)
					countPAT %= 1000000007;
			}
		}
		else
			break;
	}
	printf("%d", countPAT);
	return 0;
}