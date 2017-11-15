#include <stdio.h>
int n;
long long solve(int n) {
	long long acc = 4;
	long long total = 1;
	for (long long a = 1;a <= n;a++) {
		total += acc;
		acc += 3;
	}
	return total;
}
int main(void) {
	scanf_s("%d", &n);
	printf("%lld\n", solve(n)%1000000004);
	return 0;
}