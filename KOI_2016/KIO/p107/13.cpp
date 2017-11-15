#include <stdio.h>
#include <vector>

using namespace std;

int n, m;
int visited[200];
vector<int> arr[200];

void solve(int v, int c) {
	visited[v] = c;
	int can = 1;
	for (int a = 0;a < arr[v].size(); a++)
		if (visited[arr[v][a]] == c) {
			can = 0;
		}
	if (!can) {
		visited[v] = 0;
		return;
	}
	for (int a = 0;a < arr[v].size(); a++) {
		if (!visited[arr[v][a]]) {
			solve(arr[v][a], 1);
			solve(arr[v][a], 2);
		}
	}
}

int main(void) {
	scanf_s("%d %d", &n, &m);
	for (int a = 0;a < m;a++) {
		int s, e;
		scanf_s("%d %d", &s, &e);
		arr[s].push_back(e);
		arr[e].push_back(s);
	}
	solve(0, 1);
	for (int a = 0;a < n;a++) {
		if (visited[a] == 0) {
			printf("impossible\n");
			return 0;
		}
	}
	printf("ok\n");
	return 0;
}
