#include <stdio.h>

int main() {
	int num, shout1, hand1, shout2, hand2, count1 = 0, count2 = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d%d%d%d", &shout1, &hand1, &shout2, &hand2);
		if (hand1 == shout1 + shout2 && hand2 != shout1 + shout2)
			count2++;
		else if (hand1 != shout1 + shout2 && hand2 == shout1 + shout2)
			count1++;
	}
	printf("%d %d", count1, count2);
	return 0;
}