#include <stdio.h>

int n, k;
int arr[1000001];

/*
* it returns array index starting by 1.
*/
int LSsearch(int s, int e) {
	if (s > e) return -1;
	int mid;
	mid = (s + e) / 2;
	if (arr[mid] == k) { // arr[mid] is k -> return mid
		return mid + 1;
	}
	if (arr[mid] <= k) { // arr[mid] is less than k -> return recursive LSsearch(mid+1,e)
		return LSsearch(mid+1, e);
	}
	else if (arr[mid] > k) { // arr[mid] is grater than k -> return recursive LSsearch(s,mid-1)
		return LSsearch(s, mid - 1);
	}
}

int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", &arr[a]);
	}
	scanf_s("%d", &k);
	printf("%d\n", LSsearch(0, n - 1));
	return 0;
}