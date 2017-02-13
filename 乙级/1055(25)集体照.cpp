#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct person Person;
struct person {
	char name[10];
	int height;
};

#define MAXNUM 10010
Person people[MAXNUM];
Person ans[10][MAXNUM];

bool cmp(Person a, Person b) {
	if (a.height != b.height)
		return a.height > b.height;
	else
		return strcmp(a.name, b.name) <= 0; //strcmp，当前面字符串大于后面时，返回正值；相等返回0；小于返回负值
}

int main() {
	int num, row;
	scanf("%d%d", &num, &row);
	for (int i = 0; i < num; i++)
		scanf("%s%d", &people[i].name, &people[i].height);

	sort(people, people + num, cmp);

	int rowsize = num / row;
	int lastrowsize = num - rowsize * row + rowsize;
	int peopleID = 0; //记录安排到哪个人了
	int lastmiddle = lastrowsize / 2; //在数组中的位置要比实际的位置小1
	int lastcount = lastrowsize, move = 1, left0right1 = 0;//先给中间的左边安排位置

	//给最后一排的中间安排位置
	ans[row - 1][lastmiddle] = people[peopleID];
	peopleID++;
	lastcount--;
	//给最后一排的其他位置安排
	while (lastcount > 0) {
		if (left0right1 == 0) {
			ans[row - 1][lastmiddle - move] = people[peopleID];
			left0right1 = 1;
		}
		else{
			ans[row - 1][lastmiddle + move] = people[peopleID];
			left0right1 = 0;
			move++;
		}
		peopleID++;
		lastcount--;
	}

	//输出最后一排位置
	for (int i = 0; i < lastrowsize; i++) {
		if (i == 0)
			printf("%s", ans[row - 1][i].name);
		else
			printf(" %s", ans[row - 1][i].name);
	}
	printf("\n");

	//给其他排安排位置
	int middle = rowsize / 2; //在数组中的位置要比实际的位置小1
	for (int i = row - 2; i >= 0; i--) {
		int count = rowsize, move = 1, left0right1 = 0;
		ans[i][middle] = people[peopleID];
		peopleID++;
		count--;
		while (count > 0) {//再给其他位置安排人
			if (left0right1 == 0) {
				ans[i][middle - move] = people[peopleID];
				left0right1 = 1;
			}
			else {
				ans[i][middle + move] = people[peopleID];
				left0right1 = 0;
				move++;
			}
			peopleID++;
			count--;
		}
		//输出结果
		for (int j = 0; j < rowsize; j++) {
			if (j == 0)
				printf("%s", ans[i][j].name);
			else
				printf(" %s", ans[i][j].name);
		}
		printf("\n");
	}
	return 0;
}
