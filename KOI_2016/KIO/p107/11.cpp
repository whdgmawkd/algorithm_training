#include <stdio.h>
#define MAXV 999999

int mem[101];
int cost[101];
int apps;
int need;

void input() {
	scanf_s("%d %d", &apps, &need);
	for (int a = 1;a <= apps;a++) {
		scanf_s("%d", &mem[a]);
	}
	for (int a = 1;a <= apps;a++) {
		scanf_s("%d", &cost[a]);
	}
}

int min(int a, int b) {
	return a < b ? a : b;
}

int f(int i, int r) {
//	printf("%d %d\n", i, r);
	if (i == 0) {
		if (r <= 0)
			return 0;
		else
			return MAXV;
	}
	else if (r < 0) {
		return f(i - 1, r);
	}
	else {
		return min(f(i - 1, r), f(i - 1, r - mem[i]) + cost[i]);
	}
}

int main(void) {
	input();
	printf("%d", f(apps, need));
	return 0;

}