#include <stdio.h>
#define tick 100

int main() {
	int start, end;
	scanf("%d%d", &start, &end);
	int time = (((float) (end - start)) / 100 + 0.5); //浮点数变int的时候，先加0.5在变int与四舍五入效果一致。
	int hou = time / 3600;
	int min = (time - hou * 3600) / 60;
	int sec = time % 60;
	printf("%02d:%02d:%02d", hou, min, sec);
	return 0;
}