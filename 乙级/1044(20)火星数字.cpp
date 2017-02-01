#include <stdio.h>
#include <string.h>

/*这类题要特别注意运算的规则，仔细看题意和样例。比如这个题里，13进制的两位数，如果个位不为0，就输出“十位 个位”，但是个位为1的话，就只输出“个位”。
也就是说，0这个字符只在值为0的时候输出。别的时候都不输出。*/
int power(int a, int b) {
	int ans = 1;
	for (int i = 0; i < b; i++) 
		ans *= a;
	return ans;
}
int str2int(char str[]) {
	int len = strlen(str), ans = 0;
	for (int i = 0; i < len; i++) {
		ans += (str[i] - '0') * power(10, len - i - 1);
	}
	return ans;
}

int main() {
	char mar[13][5] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	char marhigh[12][5] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

	int num; char total[10], str1[5], str2[5], enter;
	scanf("%d", &num);
	scanf("%c", &enter);//吃掉回车
	for (int i = 0; i < num; i++) {
		gets_s(total);
		if (total[0] >= '0' && total[0] <= '9') {//说明是数字
			int number = str2int(total);
			int tenth = number / 13;
			int ones = number % 13;
			if (tenth > 0) {
				if (ones == 0) //如果个位是0，按照样例里给的规则，不输出
					printf("%s\n", marhigh[tenth - 1]);
				else {
					printf("%s ", marhigh[tenth - 1]);
					printf("%s\n", mar[ones]);
				}
			}
			else//只有个位，那么无论是不是0，都输出
				printf("%s\n", mar[ones]);
		}
		else {//说明是火星文
			int two_digit_flag = 0, stopid;
			//如果是一位的火星文，就会直接到结束符而没有空格，直接在列表里找到打印
			for (int i = 0; i < 10; i++) {
				if (total[i]) {
					if (total[i] == ' ') {
						two_digit_flag = 1;
						str1[i] = '\0';
						stopid = i;
						break;
					}
					else {
						str1[i] = total[i];
					}
				}
				else {
					str1[i] = '\0';
					break;
				}
			}

			if (!two_digit_flag) { //说明是一位火星文
				int find = 0;
				for (int i = 0; i < 13; i++) {
					if (!strcmp(mar[i], total)) {
						printf("%d\n", i);
						find = 1; //在个位数就找到了
						break;
					}
				}
				if (!find) {
					for (int i = 0; i < 12; i++) {
						if (!strcmp(marhigh[i], total)) {
							printf("%d\n", (i + 1) * 13);
							break;
						}
					}
				}
			}
			else {//两位的火星文
				int sum = 0;
				for (int i = stopid + 1; i < stopid + 5; i++) {
					if (total[i]) {
						str2[i - stopid - 1] = total[i];
					}
					else {
						str2[i - stopid - 1] = '\0';
						break;
					}
				}
				for (int i = 0; i < 13; i++) {
					if (!strcmp(mar[i], str2)) {
						sum += i;
						break;
					}
				}
				for (int i = 0; i < 12; i++) {
					if (!strcmp(marhigh[i], str1)) {
						sum += (i + 1) * 13;
						break;
					}
				}
				printf("%d\n", sum);
			}
		}
	}
	return 0;
}