#include <stdio.h>
int chk[101];
int graph[101][101];
int order[101][2];
int v, e;
void dfs(int cur) {
	printf("%d ", cur);
	for (int a = 1;a <= v;a++) {
		if (graph[cur][a] == 1 && chk[a] == 0) {
			chk[a] = 1;
			dfs(a);
		}
	}
	return;
}
int main(void) {
	scanf_s("%d %d", &v, &e);
	int num1,num2;
	for (int a = 1;a <= e;a++) {
		scanf_s("%d %d", &num1, &num2);
		order[a][0] = num1;
		order[a][1] = num2;
		graph[num1][num2] = 1;
		graph[num2][num1] = 1;
	}
	chk[1] = 1;
	dfs(1);
}