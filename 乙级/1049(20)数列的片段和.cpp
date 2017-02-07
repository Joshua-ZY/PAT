#include <stdio.h>

//!!!类型转换与舍入误差！！！

/*思路：数列的规律是如果总共有n个数，那就有n + (n - 1) + (n - 2) + ... + 1 = (n + 1) * n / 2个片段，
其中出现第一个数字有1 * n次，第二个数字出现2 * (n - 1)次，第三个出现3 * (n - 2)次...最后一个数字出现n * 1次。
因此就可以计算和了。*/

int main() {
	int num;
	double number, sum = 0;
	scanf("%d", &num);
	int times1 = num, times2 = 1;
	for (int i = 0; i < num; i++) {
		scanf("%lf", &number);
		/*这里要注意，前面两个int要强转成double在计算，否则会有舍入误差，导致某些测试点过不了。C语言中一个计算只有一个数据成分，
		但是这里有好几个计算。如果前面两个int不强转，那么就是int乘int，结果为int，再和后面的double相乘，结果为double。这其中就
		舍入误差。如果把前面两个强转，那么就是三个double相乘，误差就会减小了。此外也可以用number * times1 * times2，效果和强转
		一样，因为前面double乘int，int就会转成double，结果也是double，在于int相乘，同样int也要转成double再乘，这样其实也相当于
		三个double连乘。*/
		sum += (double) times1 * (double) times2 * number;
		times1--; times2++;
	}
	printf("%.2f\n", sum);
	return 0;
}