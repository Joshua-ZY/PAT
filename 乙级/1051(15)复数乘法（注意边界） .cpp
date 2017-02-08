#include <stdio.h>
#include <math.h>
int main() {
	double R1, P1, R2, P2, realans, imagans;
	scanf("%lf%lf%lf%lf", &R1, &P1, &R2, &P2);
	realans = R1 * cos(P1) * R2 * cos(P2) - R1 * sin(P1) * R2 * sin(P2);
	imagans = R1 * cos(P1) * R2 * sin(P2) + R1 * sin(P1) * R2 * cos(P2);
	/*边界情况：当输出值在-0.005~0之间，则会四舍五入到-0.00，但是应该输出0.00。*/
	if (realans >= -0.005 && realans <= 0)
		realans = 0;
	if (imagans >= -0.005 && imagans <= 0)
		imagans = 0;
	if (imagans < 0)
		printf("%.2f%.2fi\n", realans, imagans);
	else
		printf("%.2f+%.2fi\n", realans, imagans);

	return 0;
}