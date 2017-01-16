#include <stdio.h>
#include <algorithm>

using namespace std;

int findMaxNum(unsigned int numarr[], unsigned long int mult, int start, int end) {//二分查找的思想
	if (start == end) {
		if (numarr[start] <= mult)
			return start;
		else
			return start - 1;
	}
	if (numarr[(start + end) / 2] < mult)
		return findMaxNum(numarr, mult, (start + end) / 2 + 1, end);
	else if (numarr[(start + end) / 2] > mult)
		return findMaxNum(numarr, mult, start, (start + end) / 2 - 1);
	else //恰好找到相等的点（假设给的数列中没有值重复的点，不知道对不对）
		return (start + end) / 2;
}

int main() {
	int num;
	unsigned int p, numarr[100000];
	scanf("%d%d", &num, &p);
	for (int i = 0; i < num; i++) {
		scanf("%d", &numarr[i]);
	}
	
	sort(numarr, numarr + num);
	int ans, maxans = 0;
	for (int i = 0; i < num; i++) {
		unsigned long int mult = numarr[i] * p;
		ans = findMaxNum(numarr, mult, i, num - 1) - i + 1;
		if (ans > maxans)
			maxans = ans;
		if (num - i - 1 < ans) //如果剩下的数列的总数都没有现有答案高，那么更后面的答案就不可能超过现有的答案，所以没必要继续
			break;
	}
	printf("%d\n", maxans);
	return 0;
}