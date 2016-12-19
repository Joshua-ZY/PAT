#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXSTU 100010
typedef struct student STUDENT;
struct student {
	int id;
	int de;
	int cai;
	int category; //考生类别，其实这个题就是个排序，优先按照类别排序，如果类别相同，在按照总分排序
};

STUDENT stulist[MAXSTU];

bool cmp(STUDENT a, STUDENT b) {
	if (a.category != b.category)
		return a.category < b.category; //排在前面的类的编号要小
	else if (a.de + a.cai != b.de + b.cai)
		return a.de + a.cai > b.de + b.cai; //排在前面的总分高
	else if (a.de != b.de)
		return a.de > b.de;//排在前面的德分高
	else
		return a.id < b.id; //排在前面的考号小
}

int main() {
	int stunum, lowline, highline, numLowline = 0;
	scanf("%d%d%d", &stunum, &lowline, &highline);
	for (int i = 0; i < stunum; i++) {
		scanf("%d%d%d", &stulist[i].id, &stulist[i].de, &stulist[i].cai);
		if (stulist[i].de >= lowline && stulist[i].cai >= lowline) { //有一项达不到最低线的人不输出
			numLowline++;
			if (stulist[i].de >= highline && stulist[i].cai >= highline)
				stulist[i].category = 1;
			else if (stulist[i].de >= highline)
				stulist[i].category = 2;
			else if (stulist[i].de >= stulist[i].cai)
				stulist[i].category = 3;
			else //这一类包含很多种可能，比如才分到线德分不到线等等，总之前面几类必须严格按照题目条件划分，这一类才能是对的
				stulist[i].category = 4; 
		}
		else
			stulist[i].category = 5; //这一类不输出
	}

	sort(stulist, stulist + stunum, cmp);

	printf("%d\n", numLowline);
	for (int i = 0; i < numLowline; i++)
		printf("%d %d %d\n", stulist[i].id, stulist[i].de, stulist[i].cai);
	return 0;
}