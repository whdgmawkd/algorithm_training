#include <stdio.h>

int arr[100][100];
int w, h;
int n, m;

int solve() {
	int max = -123456789;
	int tmp = 0;

	for (int a = 0;a <= n - w;a++) { // 2 - 1
		for (int b = 0;b <= m - h;b++) { // 6 - 3
			for (int c = 0;c < w;c++) {
				for (int d = 0;d < h;d++) {
					tmp += arr[a + c][b + d];
				}
			}
			if (tmp > max)
				max = tmp;
			tmp = 0;
		}
	}
	return max;
}

int main(void) {
	scanf_s("%d %d", &n, &m);
	scanf_s("%d %d", &w, &h);
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < m;b++) {
			scanf_s("%d", &arr[a][b]);
		}
	}

	printf("%d\n", solve());
	return 0;
}