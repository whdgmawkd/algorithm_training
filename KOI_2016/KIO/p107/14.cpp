#include <stdio.h>

int max=0x80000000, n;
int arr[101];

void solve(void) {
	for (int a = 0;a < n;a++) {
		for (int b = a;b < n;b++) {
			int sum = 0;
			for (int c = a;c <= b;c++) {
				sum += arr[c];
				if (sum > max)
					max = sum;
			}
		}
	}
}

int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", &arr[a]);
	}
	solve();
	printf("%d", max);
	return 0;
}