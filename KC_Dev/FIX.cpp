#include <stdio.h>
int diff[12];
int n, t, cnt;
int main(void) {
	scanf_s("%d", &t);
	for (int a = 0;a < t;a++) {
		scanf_s("%d", &n);
		for (int b = 0;b < n;b++) {
			scanf_s("%d", &diff[b]);
		}
		for (int b = 0;b < n;b++) {
			if (diff[b] == b + 1) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
}