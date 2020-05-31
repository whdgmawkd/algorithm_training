#include <stdio.h>
int c, n, area;
int arr[20001];
int max = -1;
int getArea(int base,int index) {
	int l=0, r=n-1;
	int area;
	for (int a = index;a >= 0;a--) {
		if (arr[a] < base) {
			l = a + 1;
			break;
		}
	}
	for (int a = index;a < n;a++) {
		if (arr[a] < base) {
			r = a - 1;
			break;
		}
	}
	area = (r - l + 1)*base;
	return area;
}
int main(void) {
	scanf_s("%d", &c);
	for (int a = 0;a < c;a++) {
		max = -1;
		scanf_s("%d", &n);
		for (int b = 0;b < n;b++) {
			scanf_s("%d", &arr[b]);
		}
		for (int b = 0;b < n;b++) {
			area = getArea(arr[b], b);
			if (area > max) {
				max = area;
			}
		}
		printf("%d\n", max);
	}
}