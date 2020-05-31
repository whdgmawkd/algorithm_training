#include <stdio.h>
int c, n;
int tri[101][101];
void solve() {
	for (int a = n - 2;a >= 0;a--)
		for (int b = 0;b <= a+1;b++)
			tri[a][b] = tri[a + 1][b] > tri[a + 1][b + 1] ? tri[a][b] + tri[a + 1][b] : tri[a][b] + tri[a + 1][b + 1];
}
int main(void) {
	scanf_s("%d", &c);
	for (int a = 0;a < c;a++) {
		scanf_s("%d", &n);
		for (int b = 0;b < n;b++)
			for (int d = 0;d <= b;d++)
				scanf_s("%d", &tri[b][d]);
		solve();
		printf("%d\n", tri[0][0]);
	}
}