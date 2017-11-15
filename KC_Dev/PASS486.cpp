#include <stdio.h>
int c, n, lo, hi;
int countDiv(int num) {
	int cnt = 0;
	int a;
	for (a = 1;a*a < num;a++) {
		if (num%a == 0) {
			cnt += 2;
		}
		if (cnt > n) {
			return 0;
		}
	}
	if (a*a == num) {
		cnt += 1;
	}
	if (cnt == n)
		return 1;
	return 0;
}
int main(void) {
	scanf_s("%d", &c);
	while (c--) {
		scanf_s("%d %d %d", &n, &lo, &hi);
		int rst = 0;
		for (int a = lo;a <= hi;a++) {
			if (countDiv(a)) {
				rst++;
			}
		}
		printf("%d\n", rst);
	}
}