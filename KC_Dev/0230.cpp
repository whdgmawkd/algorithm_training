#define __0230_AND_0231__
#include <stdio.h>
#include <thread>
using namespace std;

int arr[21];
int chk[21];
int n, k;
int rst;

int solve(int sum, int cnt);

int main(void) {
	scanf_s("%d %d", &n, &k);
	for (int a = 0;a < n;a++)
		scanf_s("%d", arr + a);
	solve(0,0);
	if (rst == 1)
		printf("YES");
	else
		printf("NO");
	return 0;
}

int solve(int sum, int cnt) {
	if (sum == k) {
		rst = 1;
		return 0;
	}
	if (sum > k)
		return 0;
	for (int a = 0;a < n;a++) {
		if (chk[a] == 0 && sum+arr[a]<=k) {
			chk[a] = 1;
			thread t1 = thread(solve, sum + arr[a], cnt++);
			t1.join();
//			solve(sum + arr[a], cnt++);
			chk[a] = 0;
		}
	}
}