#include <stdio.h>


int S[81];
int n, end;

// 
bool same(int, int);
int good(int);
void solve(int);

int main(void) {
	scanf_s("%d", &n);
	solve(1);
	return 0;
}

bool same(int a, int b) {
	int i;
	for (i = a;i < b;i++) {
		if (S[i] != S[i + b - a]) {
			break;
		}
	}
	return (a == b ? false : i == b);
}

int good(int m) {
	int i, j;
	for (i = m - 1, j = m;i > 0;i -= 2, j -= 1) {
		if (same(i, j)) {
			return 0;
		}
	}
	return 1;
}

void solve(int k) {
	if (end)
		return;
	if (k > n) {
		end = 1;
		for (int i = 1;i <= n;i++) {
			printf("%d", S[i]);
		}
		return;
	}
	for (int i = 1;i <= 3;i++) {
		S[k] = i;
		if (good(k))
			solve(k + 1);
		S[k] = 0;
	}
}