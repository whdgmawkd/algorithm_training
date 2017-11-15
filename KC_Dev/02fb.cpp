#define __NO_TIME_OPTIMIZED__
#include <stdio.h>
int n;
int c = 2;
int check(int);
int main(void) {
	scanf_s("%d", &n);
	while (n >= 2) {
		if (check(c) && n%c == 0) {
			printf("%d ", c);
			n /= c;
		}
		else {
			if (c % 2 == 0)
				c++;
			else
				c += 2;
		}
	}
}
int check(int n) {
	for (int a = 3;a*a <= n;a+=2) {
		if (a%n == 0)
			return 0;
	}
	return 1;
}