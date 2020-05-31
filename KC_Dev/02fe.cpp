#define __CASE9_FAILED_TIMEOUT__
#include <stdio.h>

int arr[1000001];
typedef struct _range {
	int start;
	int end;
}Range;
Range tests[1001];
int n, k;
int printMax(int);
int main(void) {
	scanf_s("%d", &n);
	scanf_s("%d", &k);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", arr + a);
	}
	for (int a = 0;a < k;a++) {
		scanf_s("%d %d", &tests[a].start, &tests[a].end);
	}
	for (int a = 0;a < k;a++) {
		printMax(a);
	}
	return 0;
}
int printMax(int index) {
	int s = tests[index].start;
	int e = tests[index].end;
	int max = 0x80000000;
	for (int a = s-1;a < e;a++) {
		if (arr[a] > max)
			max = arr[a];
	}
	printf("%d\n", max);
	return 0;
}