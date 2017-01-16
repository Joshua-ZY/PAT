#include <stdio.h>
#include <string.h>
int main() {
	int isCharBroken[26] = { 0 }, isNumBroken[10] = { 0 }, is_Broken = 0;//用于避免重复输出
	char before[81] = { '\0' }, after[81] = { '\0' };//因为before回比after长，可能会与after后面没有赋值的部分比较，所以要初始化成有意义的值
	gets_s(before);//提交时要改成gets()
	gets_s(after);//提交时要改成gets()

	int len = strlen(before);
	int afterID = 0, brokenCount = 0;
	for (int i = 0; i < len; i++) {
		if (before[i] == after[afterID])
			afterID++;
		else {//说明坏掉了
			if (before[i] >= 'A' && before[i] <= 'Z' && !isCharBroken[before[i] - 'A']) {
				isCharBroken[before[i] - 'A'] = 1;
				printf("%c", before[i]);
			}
			else if (before[i] >= 'a' && before[i] <= 'z' && !isCharBroken[before[i] - 'a']) {
				isCharBroken[before[i] - 'a'] = 1;
				printf("%c", before[i] - 'a' + 'A');
			}
			else if (before[i] >= '0' && before[i] <= '9' && !isNumBroken[before[i] - '0']) {
				isNumBroken[before[i] - '0'] = 1;
				printf("%c", before[i]);
			}
			else if (before[i] == '_' && !is_Broken) {
				is_Broken = 1;
				printf("_");
			}
			else
				continue;
		}
	}
	printf("\n");
	return 0;
}