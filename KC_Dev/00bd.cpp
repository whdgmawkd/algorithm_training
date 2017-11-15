#include <stdio.h>
char maze[101][101];
int h, w, len=0x7fffffff;
int ex, ey;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int findMaze(int px, int py, int steps);
int main(void) {
	int sx, sy;
	scanf_s("%d %d", &h, &w);
	for (int a = 0;a < h;a++) {
		scanf_s("%s", maze[a], 101);
	}
	for (int a = 0;a < h;a++) {
		for (int b = 0;b < w;b++) {
			if (maze[a][b] == 'S') {
				sx = a;
				sy = b;
			}
			if (maze[a][b] == 'G') {
				ex = a;
				ey = b;
				maze[a][b] = '.';
			}
		}
	}
	findMaze(sx, sy, 0);
	printf("%d\n", len);
	return 0;
}
int findMaze(int px, int py, int steps) {
	maze[px][py] = steps+'0';
	if (px == ex&&py == ey) {
		if (steps < len)
			len = steps;
		return steps;
	}
	steps++;
	for (int a = 0;a < 4;a++) {
		if (maze[px + dx[a]][py + dy[a]] == '.')
			findMaze(px + dx[a], py + dy[a], steps);
	}
	return -1;
}