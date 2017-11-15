#include <stdio.h>

int rechargeCost;
int billCnt;
int billCost[11];

int recharge(int remaining, int coinCnt) {
	if (remaining == 0) {
		return coinCnt;
	}
	for (int a = billCnt - 1;a >= 0;a--) {
		if (remaining >= billCost[a]) {
			return recharge(remaining - billCost[a], coinCnt + 1);
		} 
	}
}

int main(void) {
	scanf_s("%d", &rechargeCost);
	scanf_s("%d", &billCnt);
	for (int a = 0;a < billCnt;a++) {
		scanf_s("%d", &billCost[a]);
	}
	printf("%d\n", recharge(rechargeCost, 0));
	return 0;
}