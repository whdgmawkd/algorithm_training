#include <stdio.h>
int t, n, m, num, max;
int arr[10001];
int main(void) {
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d %d", &n, &m);
		int arr[10001] = { 0, };
		for (int a = 0;a < n;a++) {
			scanf_s("%d", &num);
			if (num > max)
				max = num;
			arr[num]++;
		}
		int sum = 0, no = 0;
		while (no < m) {
			if (max == 0)
				break;
			if (arr[max] != 0) {
				sum += max;
				arr[max]--;
				arr[max - 1]++;
				no++;
			}
			else
				max--;
		}
		printf("%d\n", sum);
	}
	return 0;
}