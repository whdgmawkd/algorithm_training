#include <stdio.h>
char map[101][101];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int n, m;
int solve(int, int);
int main(void) {
	scanf_s("%d %d", &n, &m);
	for (int a = 0;a < n;a++)
		scanf_s("%s", &map[a],101);
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < m;b++) {
			solve(a, b);
		}
	}
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < m;b++) {
			printf("%c", map[a][b]);
		}
		printf("\n");
	}
	return 0;
}
int solve(int x, int y) {
	int cnt = 0;
	if (map[x][y] == '*')
		return 0;
	if (map[x][y] == '.') {
		for (int a = 0;a < 8;a++) {
			if (map[x + dx[a]][y + dy[a]] == '*')
				cnt++;
		}
	}
	map[x][y] = cnt+'0';
	return 0;
}