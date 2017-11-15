#include <stdio.h>
int n;
int num;
int bin[8];
int orig[4];
void toBin(int num) {
	for (int a = 7;a >= 1;a--) {
		bin[a] = num % 2;
		num /= 10;
	}
}
void findOrig() {
	int sw = 1;
	int skip =-1;
	int p = 0;
	int rst=0;
	for (int a = 4;a > 0;a/=2) {
		p = 0;
		sw = a;
		skip = -1;
		for (int b = a;b < 8;b++) {
			if (skip == -1) {
				p ^= bin[b];
			}
			if (sw == 1||sw==-1) {
				sw = a;
				skip *= -1;
			}
			else
				sw--;
		}
		rst = rst << 1;
		rst += p;
	}
	if (bin[rst] == 0) {
		bin[rst] = 1;
	}
	else {
		bin[rst] = 0;
	}
	printf("%d%d%d%d\n", bin[3], bin[5], bin[6], bin[7]);
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", &num);
		toBin(num);
		findOrig();
	}
}