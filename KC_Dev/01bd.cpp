#define __FAILED_CASE3__
#include <stdio.h>
int rank[2001];
int score[2001];
int n;

int calcRank();

int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++)
		scanf_s("%d", score + a);
	calcRank();
	for (int a = 0;a < n;a++) {
		printf("%d\n", rank[a]);
	}
	return 0;
}

int calcRank() {
	int rankIndex = 0;
	int prevMax = -1;
	int prevMaxRank = 0;
	int acc=1;
	while (1) {
		int max = -1;
		int maxIndex = 0;
		rankIndex += acc;
		for (int a = 0;a < n;a++) {
			if (score[a] >= max) {
				max = score[a];
				maxIndex = a;
			}
		}
		acc = 0;
		for (int a = 0;a < n;a++) {
			if (score[a] == max) {
				acc++;
				score[a] = 0;
				rank[a] = rankIndex;
			}
		}
		if (rankIndex == n)
			return 0;
	}
}