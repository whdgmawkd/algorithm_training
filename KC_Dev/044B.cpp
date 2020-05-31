#define __UNSOLVED__
#include <stdio.h>
int n, m;
int main(void) {
	scanf_s("%d %d", &n, &m);
	long rst = 1;
	for (int a = 1;a <= m;a++) {
		rst *= n;
	}
	printf("%ld\n", rst);
	return 0;
}