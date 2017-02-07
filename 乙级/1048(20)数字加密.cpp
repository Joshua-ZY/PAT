#include <stdio.h>
#include <string.h>

#define MAXCHAR 101

/*这个题里隐含的意思应该就是如果一个数的位数过小，就要在前面加0来补齐*/

char encodeOdd(char cA, char cB) {
	int num = cA + cB - '0' * 2;
	num %= 13;
	if (num < 10)
		return num + '0';
	else switch (num)
	{
	case(10):return 'J';
	case(11):return 'Q';
	case(12):return 'K';
	}
}

char encodeEven(char cA, char cB) {
	if (cB - cA < 0)
		return cB - cA + 10 + '0';
	else
		return cB - cA + '0';
}

int main() {
	char numA[MAXCHAR], numB[MAXCHAR], numAns[MAXCHAR] = { '\0' };
	scanf("%s %s", numA, numB);
	int id1 = strlen(numA) - 1; //这样id1就是数字A的末位ID
	int id2 = strlen(numB) - 1; //这个id是从0开始的，所以id为偶数，位数就是奇数
	int isOdd = 1;
	if (id2 >= id1) {
		while (id1 >= 0) {
			if (isOdd) {
				numAns[id2] = encodeOdd(numA[id1], numB[id2]); //最后一位就是个位，因此从后往前就是按照奇数、偶数这样来的
				isOdd = 0;
			}
			else {
				numAns[id2] = encodeEven(numA[id1], numB[id2]);
				isOdd = 1;
			}
			id1--; id2--;
		}
		while (id2 >= 0) {//加密数前面没有了，补上0，被加密数其实不变，所以直接复制被加密数列即可
			numAns[id2] = numB[id2];
			id2--;
		}
	}
	else {//被加密数前面没有了，补上0，会导致有数字，因此需要考虑
		while (id2 >= 0) {
			if (isOdd) {
				numAns[id1] = encodeOdd(numA[id1], numB[id2]);
				isOdd = 0;
			}
			else {
				numAns[id1] = encodeEven(numA[id1], numB[id2]);
				isOdd = 1;
			}
			id1--; id2--;
		}
		while (id1 >= 0) {
			if (isOdd) {
				numAns[id1] = encodeOdd(numA[id1], '0');
				isOdd = 0;
			}
			else {
				numAns[id1] = encodeEven(numA[id1], '0');
				isOdd = 1;
			}
			id1--;
		}
	}
	printf("%s\n", numAns);
	return 0;
}