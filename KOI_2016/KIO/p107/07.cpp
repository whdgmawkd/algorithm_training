#include <stdio.h>
#include <algorithm>

// total vertex is 10. total adjacent is 30.
int arr[11][11];
// check if it was visited.
int chk[11];
// vertex count
int n;
// adjacent count
int m;
// minimum costs
int min = 0x7fffffff;

void input(void);
// find(v,w): v:vertex index , w:total cost
void find(int, int);

int main(void) {
	input();
	find(1, 0);
	printf("%d\n", min == 0x7fffffff ? -1 : min);
	return 0;
}

void find(int v, int w) {
	if (v == n) {
		if (w < min) {
			min = w;
			return;
		}
	}
	for (int a = 1;a <= n;a++) {
		if (!chk[a] && arr[v][a]) {
			chk[a] = 1;
			find(a, w + arr[v][a]);
			chk[a] = 0;
		}
	}
}

void input(void) {
	int a, b;
	scanf_s("%d %d", &n, &m);
	for (int i = 0;i < m;i++) {
		scanf_s("%d %d", &a, &b);
		scanf_s("%d", &arr[a][b]);
		arr[b][a] = arr[a][b];
	}
	return;
}
