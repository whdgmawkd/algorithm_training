#include <stdio.h>

int n;

// solve: return count
int solve(void);

int main(void) {
	scanf_s("%d", &n);
	printf("%d\n", solve());
	return 0;
}

int solve(void) {
	int count = 0;
	for (int a = 1;a <= n;a++) {
		for (int b = a;b <= n;b++) {
/*			for (int c = b;c <= n;c++) { // O(n^3)
				if (a + b + c == n && a + b > c) {
					printf("%d %d %d\n", a, b, c);
					count++;
				}
			} */
			if (a + b<n && n-(a+b)>=b && a+b>n-(a+b)) { // O(n^2)
//				printf("%d %d %d\n", a, b, n - (a + b));
				count++;
			}
		}
	}
	return count;
}