#include <stdio.h>

int solve(int idx, int term, int cnt);
int n, rst;

int main(void) {
	scanf_s("%d", &n);
	solve(0, 0, 0);
	printf("%d\n", rst);
	return 0;
}

int solve(int index, int term, int cnt) {
	if (index > n) {
		return 0;
	}
	if (index == n) {
		rst++;
		return 0;
	}
	if (term < 0)term = 0;
	solve(index + 1, term-1, cnt+1);
	solve(index + 2, term-1, cnt+1);
	if (term <= 0) {
		solve(index + 3, 2, cnt+1);
	}
}