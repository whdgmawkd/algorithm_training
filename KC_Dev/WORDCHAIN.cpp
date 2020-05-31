#define __TIMEOUT__
#include <stdio.h>
#include <string.h>
char dict[101][11];
int chk[101];
int c, n;
// return 0: successful, -1: unsuccessful.
void printWord(int order) {
	if (order == n + 1)
		return;
	for (int a = 0;a < n;a++) {
		if (chk[a] == order) {
			if (chk[a] == n-1) {
				printf("%s\n", dict[a]);
			}
			else {
				printf("%s ", dict[a]);
			}
		}

	}
	return printWord(order + 1);
}
int solve(int cnt,int index);
void solve_start() {
	int rst;
	for (int a = 0;a < n;a++) {
		chk[a] = 1;
		rst = solve(1,0);
		if (rst == 0) {
			printWord(1);
			return;
		}
		chk[a] = 0;
	}
	printf("IMPOSSIBLE\n");
}
int solve(int cnt,int index) {
	if (cnt == n) {
		return 0; // all word used.
	}
	char last = dict[index][strlen(dict[index]) - 1];
	for (int a = 0;a < n;a++) {
		if (chk[a] == 0) {
			if (last == dict[a][0]) {
				chk[a] = cnt;
				int rst=solve(cnt + 1, a);  // next word was found.
				if (rst == 0)
					return 0;
				chk[a] = 0;
			}
		}
	}
	return -1; // next word was not found.
}
int main(void) {
	scanf_s("%d", &c);
	while (c--) {
		scanf_s("%d", &n);
		for (int a = 0;a < n;a++) {
			scanf_s("%s", &dict[a], 10);
			chk[a] = 0;
		}
		solve_start();
	}
}