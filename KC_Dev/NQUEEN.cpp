#include <stdio.h>
int chk[12], inc[24], dec[24];
int board[12][12];
int rst;
int n,m;
int solve(int row) {
	if (row > m) {
		rst++;
		return 0;
	}
	for (int a = 1;a <= m;a++) {
		if (chk[a] == 0 && inc[row + a] == 0 && dec[m + (row - a)+1]==0) {
			chk[a] = inc[row + a] = dec[m + (row - a)+1] = 1;
			solve(row + 1);
			chk[a] = inc[row + a] = dec[m + (row - a)+1] = 0;
		}
	}
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", &m);
		solve(1);
		printf("%d\n", rst);
		rst = 0;
	}
}
