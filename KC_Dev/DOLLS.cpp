#define __TIME_LIMIT_EXCEEDED__
#include <stdio.h>
int doll[100000];
int cnt[100000];
int t, n, m;
int main(void) {
	scanf_s("%d", &t);
	for (int a = 0;a < t;a++) {
		scanf_s("%d %d", &n, &m);
		for (int b = 0;b < n;b++) {
			scanf_s("%d", &doll[b]);
			cnt[b] = 0;
		}
		while (m > 0) {
			for (int b = 0;b < n;b++) {
				if (doll[b] > 0) {
					doll[b]--;
					cnt[b]++;
					m--;
				}
			}
		}
		for (int b = 0;b < n;b++) {
			printf("%d ", cnt[b]);
		}
		printf("\n");
	}
}