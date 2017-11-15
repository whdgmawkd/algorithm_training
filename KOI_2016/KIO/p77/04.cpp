#include <stdio.h>
#include <queue>

struct VERTEX {
	int a, b;
};
int h, w, Sa, Sb, Ga, Gb;
int visited[101][101];
int DX[] = { 1,0,-1,0 };
int DY[] = { 0,1,0,-1 };
char map[101][101];

bool safe(int, int);

void input(void);

int solve(void);

int main(void) {
	input();
	printf("%d\n", solve());
	for (int a = 0;a < h;a++) {
		for (int b = 0;b < w;b++) {
			printf(" %c ", map[a][b]);
		}
		puts("");
	}
	return 0;
}

void input() {
	scanf_s("%d %d", &h, &w);
	printf("%d %d\n", h, w);
	for (int a = 0;a < h;a++) {
		scanf_s("%s", map[a], 10000);
		for (int b = 0;b < w;b++) {
			if (map[a][b] == 'S') {
				Sa = a;
				Sb = b;
			}
			else if (map[a][b] == 'G') {
				Ga = a;
				Gb = b;
				map[a][b] = '.';
			}
		}
	}
}

int solve(void) {
	std::queue<VERTEX> q;
	VERTEX v1 = { Sa,Sb };
	q.push(v1);
	while (!q.empty()) {
		VERTEX cur = q.front();
		q.pop();
		if (cur.a == Ga && cur.b == Gb) break;
		for (int a = 0;a < 4;a++) {
			int x = cur.a + DX[a];
			int y = cur.b + DY[a];
			if (safe(x, y) && !visited[x][y] && map[x][y] == '.') {
				visited[x][y] = visited[cur.a][cur.b] + 1;
				VERTEX v2 = { x,y };
				q.push(v2);
			}
		}
	}
	return visited[Ga][Gb];
}

bool safe(int a, int b) {
	return (0 <= a&& a < h) && (0 <= b&&b < w);
}