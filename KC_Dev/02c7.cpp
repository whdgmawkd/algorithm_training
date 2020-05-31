#define __CASE7_FAILED__
#include <stdio.h>

int arr[21][21];
int chk[21];
int rst=0x7fffffff, n;
void solve(int sum, int row);

int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < n;b++) {
			scanf_s("%d", &arr[a][b]);
		}
	}
	solve(0, 0);
	printf("%d", rst);
	return 0;
}

void solve(int sum, int row) {
	if (row == n) {
		if (sum < rst)
			rst = sum;
		return;
	}
	for (int a = 0;a < n;a++) {
		if (chk[a] == 0) {
			chk[a] = 1;
			solve(sum + arr[row][a], row + 1);
			chk[a] = 0;
		}
	}
}