#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int num, arr[4];
	scanf("%d", &num);
	//第一遍提交有一个案例错误，想到两种corner case，就是输入0000和6174,这就要求程序无论如何必须跑一次，所以while循环改为do while循环
	do{
		int des = 0, aes = 0;
		for (int newnum = num, i = 0; i < 4; i++) {
			arr[i] = newnum % 10;
			newnum /= 10;
		}
		sort(arr, arr + 4);
		for (int i = 0; i < 4; i++) {
			aes = aes * 10 + arr[i];
		}
		for (int i = 3; i >= 0; i--) {
			des = des * 10 + arr[i];
		}
		num = des - aes;
		printf("%04d - %04d = %04d\n", des, aes, num);
	} while (num != 0 && num != 6174);
	return 0;
}