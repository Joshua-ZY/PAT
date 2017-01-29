#include <stdio.h>

#define MAXCHAR 1001

int main() {
	int sum09[10] = { 0 }, sumaz[26] = { 0 }, sumAZ[26] = { 0 }; //提供的颜色统计
	int want09[10] = { 0 }, wantaz[26] = { 0 }, wantAZ[26] = { 0 };//需要的颜色统计
	char provide[MAXCHAR], want[MAXCHAR];
	gets_s(provide);
	gets_s(want);
	//统计提供的
	for (int i = 0; i < MAXCHAR; i++) {
		if (provide[i]) {
			if (provide[i] >= '0' && provide[i] <= '9')
				sum09[provide[i] - '0']++;
			else if (provide[i] >= 'a' && provide[i] <= 'z')
				sumaz[provide[i] - 'a']++;
			else if (provide[i] >= 'A' && provide[i] <= 'Z')
				sumAZ[provide[i] - 'A']++;
		}
		else
			break;
	}
	//统计需要的
	for (int i = 0; i < MAXCHAR; i++) {
		if (want[i]) {
			if (want[i] >= '0' && want[i] <= '9')
				want09[want[i] - '0']++;
			else if (want[i] >= 'a' && want[i] <= 'z')
				wantaz[want[i] - 'a']++;
			else if (want[i] >= 'A' && want[i] <= 'Z')
				wantAZ[want[i] - 'A']++;
		}
		else
			break;
	}
	//统计缺了多少
	int lack = 0;
	for (int i = 0; i < 10; i++) {
		if (want09[i] > sum09[i])
			lack += want09[i] - sum09[i];
	}
	for (int i = 0; i < 26; i++) {
		if (wantaz[i] > sumaz[i])
			lack += wantaz[i] - sumaz[i];
		if (wantAZ[i] > sumAZ[i])
			lack += wantAZ[i] - sumAZ[i];
	}
	if (lack)
		printf("No %d", lack);
	else {//如果lack等于0，说明不缺颜色
		int len = 0, wantlen = 0;
		for (int i = 0; i < 10; i++) {
			len += sum09[i];
			wantlen += want09[i];
		}
		for (int i = 0; i < 26; i++) {
			len += sumaz[i];
			wantlen += wantaz[i];
			len += sumAZ[i];
			wantlen += wantAZ[i];
		}
		printf("Yes %d", len - wantlen);
	}
	return 0;
}