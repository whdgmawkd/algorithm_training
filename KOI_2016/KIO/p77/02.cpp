#include <stdio.h>

int n, ans;
int col[10];
int inc[20];
int dec[20];

void solve(int r) {
	if (r > n) {
		ans++;
		return;
	}
	for (int a = 1;a <= n;a++) {
		if (!col[a] && !inc[r + a] && !dec[n + (r - a) + 1]) {
			col[a] = inc[r + a] = dec[n + (r - a) + 1] = 1;
			solve(r + 1);
			col[a] = inc[r + a] = dec[n + (r - a) + 1] = 0;
		}
	}
}

int main(void) {
	scanf_s("%d", &n);
	solve(1);
	printf("%d\n", ans);
}