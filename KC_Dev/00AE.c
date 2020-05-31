#include <stdio.h>
int main(void) {
	long n;
	scanf_s("%ld", &n);
	long long total = 0;
	while (n > 0) {
		for (int a = 1;a <= n;a++) 
			total += a;
		n--;
	}
	printf("%lld\n", total);
	return 0;
}
