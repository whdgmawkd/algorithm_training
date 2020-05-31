#include <stdio.h>

int arr[1001];
int n, rst;

int solve(int index, int cnt);

int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", arr + a);
	}
	for (int a = 0;a < n;a++) {
		solve(a, 1);
	}
	printf("%d\n", rst);
}

int solve(int index, int cnt) {
	if (cnt > rst)
		rst = cnt;
	for (int a = index + 1;a < n;a++) {
		if (arr[a] < arr[index])
			solve(a, cnt + 1);
	}
	return 0;
}