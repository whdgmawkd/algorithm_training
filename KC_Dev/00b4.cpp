#define __TIME_LIMIT__
#include <stdio.h>
int heap[2001];
int n, qq, nnow;
void swap(int indexA, int indexB) {
	int tmp;
	tmp = heap[indexA];
	heap[indexA] = heap[indexB];
	heap[indexB] = tmp;
}
int max(int a, int b, int c) {
	int max = 0, q;
	if (heap[a] > max) {
		max = heap[a];
		q = a;
	}
	if (heap[b] > max) {
		max = heap[b];
		q = b;
	}
	if (heap[c] > max) {
		max = heap[c];
		q = c;
	}
	return q;
}
void maxHeap() {
	int end = n / 2;
	for (int i = end;i >= 1;i--) {
		nnow = i;
		while ((qq = max(nnow, nnow * 2, nnow * 2 + 1)) != nnow) {
			swap(nnow, qq);
			nnow = qq;
		}
	}
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 1;a <= n;a++) {
		scanf_s("%d", heap + a);
	}
	maxHeap();
	for (int a = 1;a <= n;a++) {
		printf("%d ", heap[a]);
	}
	return 0;
}