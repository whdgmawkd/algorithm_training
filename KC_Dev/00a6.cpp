#include <stdio.h>
int n, cnt;
int main(void) {
	scanf_s("%d", &n);
	while (n > 0) {
		if (n > 500) {
			cnt++;
			n -= 500;
		}
		else if (n > 100) {
			cnt++;
			n -= 100;
		}
		else if (n > 50) {
			cnt++;
			n -= 50;
		}
		else {
			cnt++;
			n -= 10;
		}
	}
	printf("%d\n", cnt);
}