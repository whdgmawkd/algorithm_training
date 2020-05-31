#include <stdio.h>

int solve(int);

int main(void) {
	int n;
	scanf_s("%d", &n);
	printf("%d\n", solve(n));
	return 0;
}

int solve(int n) {
	int sum = 0;
	for (int a = 1;a <= n;a++) {
		if (n%a == 0) {
			sum += a;
		}
	}
	return sum;
}