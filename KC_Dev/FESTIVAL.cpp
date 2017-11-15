#include <stdio.h>
int cost[1001];
int c, n, l,step;
double minimum = 1000.0;
double tmp = 0.0;
int main(void) {
	scanf_s("%d", &c);
	for (int a = 0;a < c;a++) {
		tmp = 0;
		minimum = 1000;
		scanf_s("%d %d", &n, &l);
		for (int b = 0;b < n;b++) {
			scanf_s("%d", &cost[b]);
		}
		for (int b = 0;b < n - l+1;b++) {
			step = 0;
			while (b + l + step <= n) {
				tmp = 0;
				for (int c = b;c < b + l + step;c++) {
					printf("%d %d %d %d %d %d %lf\n", a, b, c, step,cost[c],l+step,tmp);
					tmp += cost[c];
				}
				printf("%lf ", tmp);
				tmp = tmp / (l + step);
				printf("%lf\n", tmp);
				if (tmp < minimum)
					minimum = tmp;
				step++;
			}
		}

		printf("%.10lf\n", minimum);
	}
}