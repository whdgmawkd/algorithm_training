#define __CASE4_WRONG__
#define __SAME_00A8__
#include <stdio.h>
int change, coinCnt, cnt, coinOrg;
int coin[20];
int main(void) {
	scanf_s("%d %d", &change, &coinCnt);
	coinOrg = coinCnt;
	for (int a = 0;a < coinCnt;a++)
		scanf_s("%d", coin + a);
	while (change >= coin[0]) {
		coinCnt--;
		if (coinCnt < 0)coinCnt = coinOrg;
		while (change >= coin[coinCnt]) {
			change -= coin[coinCnt];
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}