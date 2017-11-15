#include <stdio.h>

int weight[7] = { 1,3,9,27,81,243,729 };
int chk[7];
int n;

bool isEnd = false;

void solve(int n, int sum) {
	if (isEnd) return;
	if (sum == n) {
		for (int c = 2;c > 0;c--) {
			for (int a = 0;a < 7;a++) {
				if (chk[a] == c) {
					printf("%d ", weight[a]);
				}
			}
			if (c == 2) {
				printf("0 ");
			}
		}
		isEnd = true;
	}
	for (int a = 0;a < 7;a++) {
		if (chk[a] == 0) {
			chk[a] = 1;
			solve(n, sum + weight[a]);
			chk[a] = 2;
			solve(n + weight[a], sum);
			chk[a] = 0;
		}
	}
}

int main(void) {
	scanf_s("%d", &n);
	printf("%d ", n);
	solve(n, 0);
	return 0;
}