#include <stdio.h>
typedef struct _item {
	int price;
	int prefer;
	int value;
}Item;
Item menu[20];
int budget, menuCnt, c, maxPrefer = 0, minPrice=0x7fffffff;
void quickSort(int left, int right) {
	Item tmp;
	int l = left, r = right;
	int pivot = menu[(left + right) / 2].value;
	while (l <= r) {
		while (menu[l].value < pivot)
			l++;
		while (pivot < menu[r].value)
			r--;
		if (l <= r) {
			tmp = menu[l];
			menu[l] = menu[r];
			menu[r] = tmp;
			l++;
			r--;
		}
	}
	if (l < right) {
		quickSort(l, right);
	}
	if (left < r) {
		quickSort(left, r);
	}
}
void solve(int c, int p) {
	while (1) {
		for (int a = 0;a < menuCnt;a++) {
			if (c + menu[a].price <= budget) {
				c += menu[a].price;
				p += menu[a].prefer;
				break;
			}
		}
		if (maxPrefer < p) {
			maxPrefer = p;
		}
		if (c + minPrice>budget)
			return;
	}
}
int main(void) {
	scanf_s("%d", &c);
	while (c--) {
		scanf_s("%d %d", &menuCnt, &budget);
		maxPrefer = 0;
		for (int a = 0;a < menuCnt;a++) {
			scanf_s("%d %d", &menu[a].price, &menu[a].prefer);
			menu[a].value = menu[a].price / menu[a].prefer; // approxiate value
			if (menu[a].price < minPrice)
				minPrice = menu[a].price;
		}
		quickSort(0, menuCnt - 1); // sort by value.
		solve(0, 0);
		printf("%d\n", maxPrefer);
	}
}