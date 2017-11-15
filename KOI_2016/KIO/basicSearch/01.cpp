#include <stdio.h>

int main(void) {
	int A[9];
	int max = -1, cnt, a;
	for (a = 0;a < 9;a++) {
		scanf_s("%d", &A[a]);
	}
	for (a = 0;a < 9;a++) {
		if (A[a] > max) {
			max = A[a];
			cnt = a;
		}	
	}
	printf("%d\n%d\n", max, cnt+1);
	return 0;
}