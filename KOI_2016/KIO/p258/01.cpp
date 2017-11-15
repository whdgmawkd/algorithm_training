#include <stdio.h>

long n;

long solve(void) {
	long sum = 0;
	long a;
	for (a = 1;a*a < n;a++) {
		if (n%a == 0)
			printf("%ld %ld\n", a, n / a);
	}
	if (a*a == n) {
		printf("%ld\n", a);
	}
	return 0;
}

int main(void) {
	scanf_s("%ld", &n);
	solve();
	return 0;
}