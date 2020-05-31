#include <stdio.h>
#include <algorithm>
#include <queue>

typedef struct VERTEX {
	int a, b;
}vertex;

int n, cnt;
int arr[101][101];
int size[101];
int DX[] = { 1,0,-1,0 };
int DY[] = { 0,1,0,-1 };

void input(void);
void solve(void);
void output(void);
void bfs(int, int, int);

bool safe(int, int);
bool cmp(int, int);

int main(void) {
	input();
	solve();
	output();
	return 0;
}

bool safe(int a, int b) {
	return (0 <= a&&a < n) && (0 <= b&&b < n);
}

bool cmp(int a, int b) {
	return a > b;
}

void bfs(int a, int b, int c) {
	std::queue<vertex> q;
	vertex v1 = { a,b };
	q.push(v1);
	arr[a][b] = c;
	while (!q.empty()) {
		VERTEX curr = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			if (safe(curr.a + DX[i], curr.b + DY[i]) &&
				arr[curr.a + DX[i]][curr.b + DY[i]] == 1) {
				arr[curr.a + DX[i]][curr.b + DY[i]] = c;
				vertex v2 = { curr.a + DX[i], curr.b + DY[i] };
				q.push(v2);
			}
		}
	}
}

void solve() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] == 1) {
				cnt++;
				bfs(i, j, cnt + 1);
			}
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j]) {
				size[arr[i][j]]++;
			}
		}
	}
	std::sort(size, size + n, cmp);
}

void input() {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < n;b++) {
			scanf_s("%d", &arr[a][b]);
		}
	}
}

void output() {
	printf("%d\n", cnt);
	for (int a = 0;a < n;a++) {
		printf("%d\n", size[a]);
	}
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < n;b++) {
			printf("%d ", arr[a][b]);
		}
		puts("");
	}
}
