#include <stdio.h>
char tree[20];
int n, index;
void dfs(int);
int main(void) {
	for (int a = 0;a < 20;a++)
		tree[a] = 0;
	scanf_s("%d", &n);
	scanf_s("%s", &tree[1], 21);
	dfs(1);
	return 0;
}

void dfs(int index) {
	if (index > n)
		return;
	printf("%c ", tree[index]);
	if (32<=tree[index * 2]&&tree[index*2]<=126)
		dfs(index * 2);
	if (32<=tree[index * 2 + 1]&&tree[index*2+1]<=126)
		dfs(index * 2 + 1);
}