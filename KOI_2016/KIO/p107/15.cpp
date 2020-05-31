#include <stdio.h>

int cnt;
int n;

void solve(int v) {
	if (v > n) {
		return;
	}
	if (v == n) {
		cnt++;
		return;
	}
	solve(v + 1);
	solve(v + 2);
}

int main(void) {
	scanf_s("%d", &n);
	solve(0);
	printf("%d", cnt);
	return 0;
}