#define __TLE__
#include <stdio.h>
int arr[50000];
int n, c;
int cnt;
void insertionSort() {
	int a, b;
	for (a = 1;a < n;a++) {
		int ins = arr[a];
		for (b = a-1;b >= 0;b--) {
			if (arr[b] > ins) {
				arr[b + 1] = arr[b];
				cnt++;
			}
			else {
				break;
			}
		}
		arr[b + 1] = ins;
	}
}
int main(void) {
	scanf_s("%d", &c);
	while (c--) {
		scanf_s("%d", &n);
		cnt = 0;
		for (int a = 0;a < n;a++) {
			scanf_s("%d", arr + a);
		}
		insertionSort();
		printf("%d\n", cnt);
	}
}