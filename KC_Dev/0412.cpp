#include <stdio.h>
#include <algorithm>
using namespace std;
long arr[100001];
int index;
int n, k;
int main(void) {
	scanf_s("%d %d", &n, &k);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", arr+a);
	}
	index=lower_bound(arr, arr + n, k)-arr+1;
	printf("%d\n", index);
	return 0;
}