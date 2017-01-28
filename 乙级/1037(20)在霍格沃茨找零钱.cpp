#include <stdio.h>
typedef struct money Money;
struct money {
	int G;
	int S;
	int K;
};

Money diff(Money larger, Money smaller) {
	Money ans;
	ans.K = larger.K - smaller.K;
	if (ans.K < 0) {
		ans.K += 29;
		larger.S--;
	}
	ans.S = larger.S - smaller.S;
	if (ans.S < 0) {
		ans.S += 17;
		larger.G--;
	}
	ans.G = larger.G - smaller.G;
	return ans;
}

int firstLarger(Money first, Money second) {
	if (first.G > second.G)
		return 1;
	else if (first.G == second.G && first.S > second.S)
		return 1;
	else if (first.G == second.G && first.S == second.S && first.K > second.K)
		return 1;
	else
		return 0;
}

int main() {
	Money pay, bring, ans;
	scanf("%d.%d.%d%d.%d.%d", &pay.G, &pay.S, &pay.K, &bring.G, &bring.S, &bring.K);
	if (firstLarger(pay, bring)) {
		printf("-");
		ans = diff(pay, bring);
		printf("%d.%d.%d\n", ans.G, ans.S, ans.K);
	}
	else {
		ans = diff(bring, pay);
		printf("%d.%d.%d\n", ans.G, ans.S, ans.K);
	}
	return 0;
}