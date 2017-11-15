#include <stdio.h>

void solve(int w, int h);

int width, height;
int cnt;

int main(void) {
	scanf_s("%d %d", &height, &width);
	solve(0, 0);
	printf("%d\n", cnt);
	return 0;
}

void solve(int h, int w) {
	if (h > height || w > width) return;
	if (h == height && w == width) {
		cnt++;
		return;
	}
	solve(h + 1, w);
	if ((double)height / width <= (double)h / (w+1)) {
		solve(h, w + 1);
	}
}