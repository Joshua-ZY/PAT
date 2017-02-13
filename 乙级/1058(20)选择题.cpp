#include <stdio.h>

#define MAXQ 105
#define MAXSTU 1005

int ans2id(char ans) {
	switch (ans)
	{
	case('a'):return 0;
	case('b'):return 1;
	case('c'):return 2;
	case('d'):return 3;
	case('e'):return 4;
	}
}

int main() {
	int stunum, quenum, ansnum, rightnum, quescore[MAXQ], queans[MAXQ][5] = { 0 }, 
		queWrongSum[MAXQ] = { 0 }, stuscore[MAXSTU] = { 0 };
	char ans;
	scanf("%d%d", &stunum, &quenum);
	//输入答案
	for (int i = 0; i < quenum; i++) {
		scanf("%d", &quescore[i]);
		scanf("%d", &ansnum);
		scanf("%d", &rightnum);
		for (int j = 0; j < rightnum; j++) {
			scanf(" %c", &ans); //注意吃掉空格
			queans[i][ans2id(ans)] = 1;
		}
	}

	/*// 验证答案正确性
	for (int i = 0; i < quenum; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d", queans[i][j]);
		}
		printf("\n");
	}
	*/
	//读入学生答案并判断
	char kuohao;//读入左右括号
	for (int i = 0; i < stunum; i++) {//i代表学生
		for (int j = 0; j < quenum; j++) {//j代表题目
			int stuans[5] = { 0 };
			scanf(" %c %d", &kuohao, &ansnum);//读入左括号和学生选的选项个数，左括号左边可能有空格，吃掉空格
			//读入答案
			for (int k = 0; k < ansnum; k++) {//k代表选项
				scanf(" %c", &ans);
				stuans[ans2id(ans)] = 1;
			}
			scanf("%c", &kuohao);//读入右括号
			
			//判断答案是否正确
			int wrong = 0;
			for (int k = 0; k < 5; k++) {
				if (stuans[k] != queans[j][k]) {
					wrong = 1;
					break;
				}
			}
			if (wrong)
				queWrongSum[j]++;
			else
				stuscore[i] += quescore[j];
		}
	}
	//输出学生成绩
	for (int i = 0; i < stunum; i++) 
		printf("%d\n", stuscore[i]);

	//统计错题数量并输出
	int maxwrong = 0;
	for (int i = 0; i < quenum; i++) {
		if (queWrongSum[i] > maxwrong)
			maxwrong = queWrongSum[i];
	}
	if (maxwrong == 0) //说明所有题目错误次数都为0，没有错题
		printf("Too simple\n");
	else {
		printf("%d", maxwrong);
		for (int i = 0; i < quenum; i++) {
			if (queWrongSum[i] == maxwrong) 
				printf(" %d", i + 1); //题号从1开始，数组中的序号从0开始 
		}
		printf("\n");
	}
	return 0;
}