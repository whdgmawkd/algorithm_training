#include <stdio.h>
#include <algorithm>


int main(void) {
	int a[] = { 3,0,1,2,3,2,4,5,9,8 };
	int res, i;
	res = 0;
	for (i = 0;i < 10;i++) {
		int p, q, len;
		p = i, q = a[i], len = 1;
		while (p != q) {
			p = a[p];
			q = a[a[q]];
		}
		q = a[q];
		while (p != q) {
			p = a[p];
			q = a[a[q]];
			len++;
		}
		if (res < len) res = len;
	}
	printf("%d", res);
}