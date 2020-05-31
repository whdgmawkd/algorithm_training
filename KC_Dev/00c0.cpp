#include <stdio.h>
typedef struct _recture {
	int s;
	int e;
}Recture;
Recture arr[100001];
int n, rst;
int solve(int time, int cnt);

int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d %d", &arr[a].s, &arr[a].e);
	}
	solve(0, 0);
	printf("%d\n", rst);
	return 0;
}

int solve(int time, int cnt) {
	if (cnt > rst)
		rst = cnt;
	for (int a = 0;a < n;a++) {
		if (arr[a].s > time) {
			solve(arr[a].e, cnt + 1);
		}
	}
	return 0;
}