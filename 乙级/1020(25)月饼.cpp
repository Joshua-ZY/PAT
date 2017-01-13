#include <stdio.h>
#include <algorithm>
using namespace std;

struct mooncake {
	float amount;
	float totalprice;
	float price;
};

bool cmp(mooncake a, mooncake b) {
	return a.price > b.price;
}

int main() {
	int kind;
	float market;
	struct mooncake mc[1000];
	scanf("%d%f", &kind, &market);
	for (int i = 0; i < kind; i++) {
		scanf("%f", &mc[i].amount);
	}
	for (int i = 0; i < kind; i++) {
		scanf("%f", &mc[i].totalprice);
	}
	for (int i = 0; i < kind; i++) {
		mc[i].price = ((float) mc[i].totalprice) / mc[i].amount;
	}

	sort(mc, mc + kind, cmp);

	int thiskind = 0;
	float money = 0;
	while (market > 0) {
		if (market >= mc[thiskind].amount) {
			money += mc[thiskind].totalprice;
			market -= mc[thiskind].amount;
			thiskind++;
		}
		else {
			money += market * mc[thiskind].price;
			market = 0;
			thiskind++;
		}
	}
	printf("%.2f\n", money);
	return 0;
}