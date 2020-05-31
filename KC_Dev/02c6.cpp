#include <stdio.h>
int chk[10];
int arr[10][10];
int n, min=0x7fffffff;
void solve(int x,int sum);
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < n;b++) {
			scanf_s("%d", &arr[a][b]);
		}
	}
	for (int a = 0;a < n;a++) {
		if (chk[a] == 0) {
			chk[a] = 1;
			solve(1, arr[0][a]);
			chk[a] = 0;
		}
	}
	printf("%d\n", min);
}
void solve(int x,int sum) {
	if (x >= n) {
		if (sum < min)
			min = sum;
		return;
	}
	for (int a = 0;a < n;a++) {
		if (chk[a] == 0) {
			chk[a] = 1;
			solve(x + 1, sum + arr[x][a]);
			chk[a] = 0;
		}
	}
}