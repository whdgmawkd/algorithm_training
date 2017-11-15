#include <stdio.h>

int arr[100];
int n, w;

int solve(void) {
	int max = -123456789;
	int tmp = 0;
	for (int a = 0;a <= n - w;a++) {
		for (int b = 0;b < w;b++) {
			tmp += arr[a + b];
		}
		if (tmp > max)
			max = tmp;
		tmp = 0;
	}
	return max;
}

int main(void) {
	scanf_s("%d", &n);
	scanf_s("%d", &w);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", &arr[a]);
	}
	printf("%d\n", solve());
	return 0;
}