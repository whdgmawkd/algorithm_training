#define __TIMEOUT__
#include <stdio.h>
bool solve(int n) {
	for (int a = 2;a*a <= n;a++) {
		if (n % (a*a) == 0) {
			return false;
		}
	}
	return true;
}
int main(void) {
	int min, max;
	int cnt = 0;
	scanf_s("%d %d", &min, &max);
	for (int a = min;a <= max;a++) {
		if (solve(a))
			cnt++;
	}
	printf("%d\n", cnt);
}