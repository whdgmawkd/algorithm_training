#include <stdio.h>
#include <algorithm>

typedef struct _WIRE {
	int l;
	int r;
} wire;
 
wire pole[100001];

int poleCnt;

// max(a,b): return bigger number
int max(int, int);

// solve(index): return count of LIS started index
int solve(int);

int max(int a, int b) {
	return a > b ? a : b;
}

int solve(int index) {
	int count = 1;
	for (int a = index + 1;a <= poleCnt;a++) {
		if (pole[index].r < pole[a].r) {
			count = max(count, solve(a) + 1);
		}
	}
	return count;
}

int main(void) {
	int tmp;
	int max = 0x80000000;
	scanf_s("%d", &poleCnt);
	for (int a = 0;a < poleCnt;a++) {
		scanf_s("%d %d", &pole[a].l, &pole[a].r);
	}
	std::sort(pole, pole + poleCnt + 1, [](wire a, wire b)->bool {return a.l < b.l;});
	for (int a = 1;a <= poleCnt;a++) {
		tmp=solve(a);
		if (tmp > max)
			max = tmp;
	}
	printf("%d\n", poleCnt - max);
	return 0;
}