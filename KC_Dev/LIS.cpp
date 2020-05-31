#define __RETIRE__
#include <stdio.h>
int c, n;
int arr[501];
int findLIS() {
	int cnt = 0, max=0,num=-1;
	for (int a = 0;a < n - 1;a++) { // start index
		for (int b = a;b < n - 1;b++) {
			if (arr[b] < arr[b + 1] && arr[b]>num) {
				cnt++;
				num = arr[b];
			}
			if (cnt > max) {
				max = cnt;
			}
		}
		cnt = 0;
	}
	return max == 0 ? 0 : max + 1;
}
int main(void) {
	scanf_s("%d", &c);
	for (int a = 0;a < c;a++) {
		scanf_s("%d", &n);
		for (int b = 0;b < n;b++) {
			scanf_s("%d", &arr[b]);
		}
		printf("%d\n", findLIS());
	}
	return 0;
}