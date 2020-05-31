#include <stdio.h>

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int h, w;
int arr[110][110];
int res;

bool isInside(int x, int y) {
	return (0 <= x&&x < h) && (0 <= y&&y < w);
}

bool isDone(void) {
	int cnt = 0;
	for (int a = 0;a < h;a++) {
		for (int b = 0;b < w;b++) {
			if (arr[a][b] == -1 || arr[a][b]>2)
				arr[a][b] = 0;
			else if (arr[a][b] == 2 || arr[a][b] == 1) {
				arr[a][b] = 1;
				cnt++;
			}
		}
	}
	return cnt == 0;
}

int solve(int x, int y) {
	arr[x][y] = -1;
	for (int a = 0;a < 4;a++) {
		if (isInside(x + dx[a], y + dy[a])) {
			if (arr[x + dx[a]][y + dy[a]] == 0) {
				solve(x + dx[a], y + dy[a]);
			}
			else if (arr[x + dx[a]][y + dy[a]]>0) {
				arr[x + dx[a]][y + dy[a]]++;
			}
		}
	}
	return 0;
}

int main(void) {
	scanf_s("%d %d", &h, &w);
	for (int a = 0;a < h;a++) {
		for (int b = 0;b < w;b++) {
			scanf_s("%d", &arr[a][b]);
		}
	}
	for (res = 0;!isDone();res++) {
		solve(0, 0);
	}
	printf("%d\n", res);
	return 0;
}
