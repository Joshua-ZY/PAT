#include <stdio.h>
#define MAXNUM 1000

typedef struct stuinfo STUINFO;
struct stuinfo{
	char no[15];
	int testno;
	int finalno;
};

int main() {
	int stunum, checknum;
	STUINFO stu[MAXNUM];
	scanf("%d", &stunum);
	for (int i = 0; i < stunum; i++) {		
		scanf("%s", stu[i].no);
		scanf("%d%d", &stu[i].testno, &stu[i].finalno);
	}

	scanf("%d", &checknum);
	int check;
	for (int i = 0; i < checknum; i++) {
		scanf("%d", &check);
		for (int j = 0; j < stunum; j++) {
			if (stu[j].testno == check) {
				printf("%s %d\n", stu[j].no, stu[j].finalno);
				break;
			}
		}
	}
	return 0;
}