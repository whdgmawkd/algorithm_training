#include <stdio.h>
#define __ULL unsigned long long
__ULL rst=1;
__ULL solve(__ULL n) {
	if (n == 0)
		return 1;
	__ULL total=0;
	for (__ULL i = 0;i < n;i++) {
		total += solve(i)*solve(n - 1 - i);
	}
	return total;
}
int main(void) {
	__ULL n;
	scanf_s("%lld", &n);
	printf("%lld\n", solve(n));
}