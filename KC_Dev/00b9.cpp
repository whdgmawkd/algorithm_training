#define __CASE3_WRONG__
#include <stdio.h>
int n, r, s = 1, tmp=1;
int fac(int n) {
	int num = 1;
	for (int a = 2;a <= n;a++) {
		num *= a;
	}
	return num;
}
int main(void) {
	scanf_s("%d %d", &n, &r);
	s = (fac(n)) / (fac(r)*fac(n - r));
	printf("%d\n", s);
	return 0;
}