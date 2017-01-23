#include <stdio.h>

#define MAXWORDS 100001

int main() {
	//分别代表各类型的键坏了没有（坏了为1，没坏为0）
	int isChar[26] = { 0 }, isNum[10] = { 0 }, is_ = 0, isComma = 0, isPeriod = 0, isSlash = 0, isShift = 0;
	char broken[100], words[MAXWORDS];

	gets_s(broken);
	gets_s(words);
	//更新损坏信息
	for (int i = 0; i < 100; i++) {
		if (broken[i]) {
			if (broken[i] >= 'a' && broken[i] <= 'z')
				isChar[broken[i] - 'a'] = 1;
			else if (broken[i] >= 'A' && broken[i] <= 'Z')
				isChar[broken[i] - 'A'] = 1;
			else if (broken[i] >= '0' && broken[i] <= '9')
				isNum[broken[i] - '0'] = 1;
			else switch (broken[i])	{
			case('_'):is_ = 1; break;
			case(','):isComma = 1; break;
			case('.'):isPeriod = 1; break;
			case('-'):isSlash = 1; break;
			case('+'):isShift = 1; break;
			}

		}
		else
			break;
	}

	for (int i = 0; i < MAXWORDS; i++) {
		if (words[i]) {
			if ((words[i] >= 'a' && words[i] <= 'z') && isChar[words[i] - 'a'] == 1)
				continue;
			else if ((words[i] >= 'A' && words[i] <= 'Z') && (isChar[words[i] - 'A'] == 1 || isShift == 1))
				continue;
			else if (words[i] >= '0' && words[i] <= '9' && isNum[words[i] - '0'] == 1)
				continue;
			else switch (words[i]) {
			case('_'):
				if (is_ == 1)
					continue;
				else
					printf("%c", words[i]);
				break;

			case(','):
				if(isComma == 1)
					continue;
				else
					printf("%c", words[i]);
				break;
			case('.'):
				if(isPeriod == 1)
					continue;
				else
					printf("%c", words[i]);
				break;
			case('-'):
				if(isSlash == 1) 
					continue;
				else
					printf("%c", words[i]);
				break;
			default: printf("%c", words[i]); break;
			}
		}
		else
			break;
	}
	printf("\n");
	return 0;
}