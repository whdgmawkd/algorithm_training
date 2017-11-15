#define __RETIRE__
#include <stdio.h>
int arr[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n, m;
int onCnt = 0x7fffffff, offCnt = 0x7fffffff;
void onSolve(int px, int py, int cnt);
void offSolve(int px, int py, int cnt);
int main(void) {
	scanf_s("%d %d", &n, &m);
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < m;b++) {
			scanf_s("%d", &arr[a][b]);
		}
	}
	onSolve(0, 0, 0);
	offSolve(0, 0, 0);
	printf("%d\n%d\n", onCnt, offCnt);
	return 0;
}
void onSolve(int px, int py, int cnt) {

}