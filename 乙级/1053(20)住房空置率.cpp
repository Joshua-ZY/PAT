#include <stdio.h>

int main() {
	int housenum, daymin, empty_possible = 0, empty = 0;
	double emin;
	scanf("%d%lf%d", &housenum, &emin, &daymin);
	for (int i = 0; i < housenum; i++) {
		int daysum = 0, day;
		double elec;
		scanf("%d", &day);
		for (int j = 0; j < day; j++) {
			scanf("%lf", &elec);
			if (elec < emin) 
				daysum++;
		}
		if (daysum > day / 2) {
			if (day > daymin)
				empty++;
			else
				empty_possible++;
		}
	}
	double epratio = (double) empty_possible / housenum * 100;
	double emptyratio = (double)empty / housenum * 100;
	printf("%.1f%% %.1f%%\n", epratio, emptyratio);
	return 0;
}