#include <stdio.h>
#include <stdlib.h>

int is_legal(char input[]) {
	int intcount = 0, floatcount = 0, periodcount = 0;
	for (int i = 0; i < 100; i++) {
		if (input[i]) {
			if (i == 0 && input[i] == '-')
				continue;
			else if (input[i] >= '0' && input[i] <= '9') {
				if (periodcount == 0)
					intcount++;
				else
					floatcount++;
			}
			else if (input[i] == '.')
				periodcount++;
			else
				return 0;
		}
		else
			break;
	}
	if (floatcount > 2 || periodcount > 1)
		return 0;
	else
		return 1;
}

int main() {
	int num;
	char input[100];
	scanf("%d", &num);
	int legalnum = 0;
	double sumlegal = 0;
	for (int i = 0; i < num; i++) {
		scanf("%s", input);
		if (is_legal(input)) {
			double number = atof(input);
			if (number < -1000 || number > 1000)
				printf("ERROR: %s is not a legal number\n", input);
			else {
				sumlegal += number;
				legalnum++;
			}
		}
		else
			printf("ERROR: %s is not a legal number\n", input);
	}
	//仔细审题！在数字大于一个或者为0个的时候，输出的是numbers，复数；在数字为1个时，输出的是number，单数！
	if (legalnum > 1)
		printf("The average of %d numbers is %.2f\n", legalnum, sumlegal / legalnum);
	else if (legalnum == 1)
		printf("The average of 1 number is %.2f\n", sumlegal);
	else
		printf("The average of 0 numbers is Undefined\n");
	return 0;
}