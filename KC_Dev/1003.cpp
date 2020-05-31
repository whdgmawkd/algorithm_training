#include <stdio.h>
int cache[41][2];
int t;
void fibonacci(int n) {
	if (n == 0) {
		cache[n][0] = 1;
	}
	else if (n == 1) {
		cache[n][1] = 1;
	}
	else {
		cache[n][0] = cache[n - 2][0] + cache[n - 1][0];
		cache[n][1] = cache[n - 2][1] + cache[n - 1][1];
	}
}
int main(void) {
	scanf_s("%d", &t);
	for (int a = 0;a <= 40;a++) {
		fibonacci(a);
	}
	while (t--) {
		int n;
		scanf_s("%d", &n);
		printf("%d %d\n", cache[n][0], cache[n][1]);
	}
}