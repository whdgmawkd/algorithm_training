#include <stdio.h>
#include <algorithm>

/*
* std::sort(s,e,condition)
*/

int input();
int output();
int solve();

/*
* dfs(a,b,c) -> change state all connected (a,b) to c
*/
void dfs(int a, int b, int c);
/*
* safe(a,b) -> check (a,b) is not overflow array
*/
bool safe(int a, int b);
/*
* cmp(a,b) -> for std::sort
*/
bool cmp(int a, int b);

int n, cnt;
int arr[101][101];
int size[101];

// for bfs condition.
int DX[] = { 1,0,-1,0 };
int DY[] = { 0,1,0,-1 };

int main(void) {
	input();
	solve();
	output();
	return 0;
}

void dfs(int a, int b, int c) {
	arr[a][b] = c;
	for (int i = 0;i < 4;i++) {
		if (safe(a + DX[i], b + DY[i]) && arr[a + DX[i]][b + DY[i]] == 1)
			dfs(a + DX[i], b + DY[i], c);
	}
}

bool safe(int a, int b) {
	if (0 <= a && a < n && 0 <= b && b < n)
		return true;
	else
		return false;
}

bool cmp(int a, int b) {
	return a > b;
}

int solve() {
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < n;b++) {
			if (arr[a][b] == 1) {
				cnt++;
				dfs(a, b, cnt + 1);
			}
		}
	}
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < n;b++) {
			if (arr[a][b]) {
				size[arr[a][b]]+=1;
			}
		}
	}
	std::sort(size, size + n, cmp);
	return 0;
}

int input() {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < n;b++) {
			scanf_s("%d", &arr[a][b]);
		}
	}
	return 0;
}

int output() {
	printf("%d\n", cnt);
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < n;b++) {
			printf("%d ", arr[a][b]);
		}
		puts("");
	}
	for (int a = 0;a < cnt;a++) {
		printf("%d\n", size[a]);
	}
	return 0;
}