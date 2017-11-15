#include <stdio.h>
#include <stdlib.h>
int c, n;
int map[101][101];
int cache[101][101];
bool possible;
int findPath(int x, int y) {
	if (x >= n || y >= n) {
		return 0;
	}
	if (x==n-1&&y==n-1) {
		possible = true;
		return 1;
	}
	if (cache[x][y] != -1) {
		return cache[x][y];
	}
	return cache[x][y] = (findPath(x + map[x][y], y) || findPath(x, y + map[x][y]));
}
int main(void) {
	scanf_s("%d", &c);
	for (int a = 0;a < c;a++) {
		scanf_s("%d", &n);
		for (int b = 0;b < n;b++) {
			for (int d = 0;d < n;d++) {
				scanf_s("%d", &map[b][d]);
				cache[b][d] = -1;
			}
		}
		possible = findPath(0, 0);
		printf("%s\n", possible ? "YES" : "NO");
		possible = false;
	}
}