#include <stdio.h>
long long fibo(long long n,long long prev,long long next) {
	if (n == 0)
		return prev;
	else
		return fibo(n - 1, next, prev + next);
}
int main(void) {
	long long a;
	scanf_s("%lld", &a);
	printf("%lld\n", fibo(a, 0, 1));
	return 0;
}