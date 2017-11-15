#define __TIMEOUT__
#include <stdio.h>
#include <string.h>
#include <memory.h>
typedef struct _object {
	char name[21];
	int weight;
	int need;
}Object;
Object pack[100];
int chk[100];
int maxChk[100];
int maxNeed;
int c, n,w;
void solve(int index, int weight, int need) {
	if (weight > w)
		return;
	if (index == n) {
		if (maxNeed < need) {
			maxNeed = need;
			memcpy_s(maxChk, sizeof(maxChk), chk, sizeof(chk));
		}
		return;
	}
	chk[index] = 1;
	solve(index + 1, weight + pack[index].weight, need + pack[index].need);
	chk[index] = 0;
	solve(index + 1, weight, need);
}
int main(void) {
	scanf_s("%d", &c);
	for (int a = 0;a < c;a++) {
		scanf_s("%d %d", &n, &w);
		for (int b = 0;b < n;b++) {
			scanf_s("%s", &pack[b].name, 20);
			scanf_s("%d %d", &pack[b].weight, &pack[b].need);
			chk[b] = 0;
		}
		solve(0, 0, 0);
		int cnt = 0;
		for (int b = 0;b < n;b++) {
			if (maxChk[b] == 1) {
				cnt++;
			}
		}
		printf("%d %d\n", maxNeed, cnt);
		for (int b = 0;b < n;b++) {
			printf("%s %d %d\n", pack[b].name, pack[b].weight, pack[b].need);

		}
		maxNeed = 0;
	}
}