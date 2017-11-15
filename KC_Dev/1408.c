#include <stdio.h>
#include "base.h"

int n;

int main(void) {
	int a, b, c, d;
	scanf_s("%d", &n);
	printFirst();
	for (a = 1;a <= n;a++) {
		for (b = 1;b <= n;b++) {
			for (c = b;c <= n;c++) {
				for (d = c;d <= n;d++) {
					if (a*a*a == b*b*b + c*c*c + d*d*d) {
						printf("Cude = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
					}
				}
			}
		}
	}
	return 0;
}