#include <stdio.h>

int n;
int m = 1000;
int p[500];
int d[500];
int g[500];

bool ca(int a, int k) {
	return p[k] <= p[a] + d[a];
}

bool cb(int b, int k) {
	return (p[k] <= p[b] + d[k]) && g[k];
}

int f(int a, int b, int k) {
	int c = 0;
	if (k == n - 1) {
		if (ca(a, k) && cb(b, k)) c = 1;
		else c = 0;
	}
	else {
		if (ca(a, k))c += f(k, b, k + 1) % m;
		if (cb(b, k))c += f(a, k, k + 1) % m;
		c += f(a, b, k + 1) % m;
	}
	return c;
}

int main(void){
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d %d %d", p + a, d + a, g + a);
	}
	printf("%d\n", f(0, 0, 1));
	return 0;
}