#include <stdio.h>
#include <string.h>
int k;
int minCnt = 0x7fffffff;
char str[1000000];
char tmp[1000000];
void inline solve(int x, int y, int cnt) {
	if (x >k || y>k||cnt>minCnt)
		return;
	if (x == k) {
		if (cnt < minCnt) {
			minCnt = cnt;
			strcpy_s(str,1000000, tmp);
		}
		return;
	}
	tmp[cnt] = 'X';
	solve(x + y, y, cnt + 1);
	tmp[cnt] = 'Y';
	solve(x, x + y, cnt + 1);
	tmp[cnt] = 0;
}
int main(void) {
	scanf_s("%d", &k);
	solve(1, 1, 0);
	printf("%d\n%s\n", minCnt, str);
	return 0;
}