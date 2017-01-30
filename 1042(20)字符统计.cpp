#include <stdio.h>
#define MAXLEN 1001

int main() {
	char str[MAXLEN];
	int appear[26] = { 0 };
	gets_s(str);
	for (int i = 0; i < MAXLEN; i++) {
		if (str[i]) {
			if (str[i] >= 'A' && str[i] <= 'Z')
				appear[str[i] - 'A']++;
			else if (str[i] >= 'a' && str[i] <= 'z')
				appear[str[i] - 'a']++;
		}
		else
			break;
	}

	int maxid, maxnum = 0;
	for (int i = 0; i < 26; i++) {
		if (appear[i] > maxnum) {
			maxnum = appear[i];
			maxid = i;
		}
	}
	printf("%c %d", maxid + 'a', maxnum);
	return 0;
}