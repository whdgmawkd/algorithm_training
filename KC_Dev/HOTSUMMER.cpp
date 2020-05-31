#include <stdio.h>
int n, max, tmp, sum;
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", &max);
		sum = 0;
		for (int b = 0;b < 9;b++) {
			scanf_s("%d", &tmp);
			sum += tmp;
		}
		if (sum > max)
			printf("NO\n");
		else
			printf("YES\n");
	}
}