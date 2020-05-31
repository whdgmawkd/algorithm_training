#include <stdio.h>
int t, m, c, rst;
int coin[101];
void solve(int m,int cI) {
//	printf("%d %d\n", m,rst);
	if (m == 0) {
		rst++;
		return;
	}
	if (m < 0) {
		return;
	}
	for (int a = cI;a < c;a++) {
		if (m - coin[a] < 0) {
			break;
		}
		solve(m - coin[a],a);
	}
}
int main(void) {
	scanf_s("%d", &t);
	for (int a = 0;a < t;a++) {
		rst = 0;
		scanf_s("%d %d", &m, &c);
		for (int b = 0;b < c;b++) {
			scanf_s("%d", &coin[b]);
		}
		solve(m,0);
		printf("%d\n", rst);
	}
}