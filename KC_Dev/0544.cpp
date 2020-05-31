#include <stdio.h>
#include <algorithm>
int graph[30001][3];
int n, comp;
void quickSort(int base, int left, int right);
void swap(int a, int b);
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) 
		scanf_s("%d %d %d", graph[a], graph[a] + 1, graph[a] + 2);
	scanf_s("%d", &comp);
	if (comp == 1||comp==2)
		quickSort(0, 0, n - 1);
	else if (comp == 3||comp==4) 
		quickSort(1, 0, n - 1);
	else if (comp == 5||comp==6) 
		quickSort(2, 0, n - 1);
	if (comp % 2 == 0) 
		for (int a = n-1;a >=0 ;a--) 
			printf("%d %d %d\n", graph[a][0], graph[a][1], graph[a][2]);
	else 
		for (int a = 0;a < n;a++) 
			printf("%d %d %d\n", graph[a][0], graph[a][1], graph[a][2]);
	return 0;
}
void quickSort(int base, int left, int right) {
	int l = left, r = right;
	int pivot = graph[(l + r) / 2][base];
	while (l <= r) {
		while (graph[l][base] < pivot)
			l++;
		while (graph[r][base] > pivot)
			r--;
		if (l <= r) {
			swap(l, r);
			l++;
			r--;
		}
	}
	if (left < r)
		quickSort(base, left, r);
	if (l < right)
		quickSort(base, l, right);
}
void swap(int a, int b) {
	int tmp;
	for (int i = 0;i < 3;i++) {
		tmp = graph[a][i];
		graph[a][i] = graph[b][i];
		graph[b][i] = tmp;
	}
}