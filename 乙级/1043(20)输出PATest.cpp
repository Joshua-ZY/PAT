#include <stdio.h>
#define MAXLEN 10001

int main() {
	char str[MAXLEN];
	int charnum[6] = { 0 }; //6个位置分别对应"PATest"
	gets_s(str);
	for (int i = 0; i < MAXLEN; i++) {
		if (str[i]) {
			switch (str[i])
			{
			case('P'):charnum[0]++; break;
			case('A'):charnum[1]++; break;
			case('T'):charnum[2]++; break;
			case('e'):charnum[3]++; break;
			case('s'):charnum[4]++; break;
			case('t'):charnum[5]++; break;
			}
		}
		else
			break;
	}

	int finish_flag = 6;
	char output[6] = { 'P','A','T','e','s','t' };
	while (finish_flag) {
		for (int i = 0; i < 6; i++) {
			if (charnum[i] > 0) {
				printf("%c", output[i]);
				charnum[i]--;
			}
			else if (charnum[i] == 0) {
				finish_flag--;
				charnum[i] = -1;
			}
		}
	}
	printf("\n");
	return 0;
}