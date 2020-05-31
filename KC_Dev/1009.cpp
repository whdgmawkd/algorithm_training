#include <stdio.h>
int main(void) {
	int t;
	scanf_s("%d", &t);
	while(t--) {
		int a, b;
		scanf_s("%d %d", &a, &b);
		int num = a;
		for (int c = 1;c < b;c++) {
			num %= 10;
			num *= a;
		}
		printf("%d\n", num%10==0?10:num%10);
	}
}