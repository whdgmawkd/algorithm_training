#include <stdio.h>
int enc[21][21];
int r, c, n;
char bin[402];
void printChar(int val) {
	if (val == 0) {
		printf(" ");
		return;
	}
		printf("%c", val + 'A' - 1);
}
void makeEnc() {
	int i = 0;
	for (int a = 1;a <= r;a++) {
		for (int b = 1;b <= c;b++) {
			enc[a][b] = bin[i]-'0';
			i++;
		}
	}
}
void decMsg() {
	int sw = 1;
	int rI = 1, cI = 0;
	int cMax = c;
	int rMax = r-1;
	int binToDec = 0;
	int bitDigit = 0;
	while (1) {
		for (int a = 1;a <= cMax;a++) {
			if (bitDigit == 5) {
				printChar(binToDec);
				binToDec = 0;
				bitDigit = 0;
			}
			binToDec = binToDec << 1;
			cI += sw;
			binToDec += enc[rI][cI];
			bitDigit++;
		}
		cMax--;
		if (cMax < 0 || rMax<=0)
			break;
		for (int a = 1;a <= rMax;a++) {
			if (bitDigit == 5) {
				printChar(binToDec);
				binToDec = 0;
				bitDigit = 0;
			}
			binToDec = binToDec << 1;
			rI += sw;
			binToDec += enc[rI][cI];
			bitDigit++;
		}
		rMax--;
		sw *= -1;
	}
	if (bitDigit == 5) {
		printChar(binToDec);
		binToDec = 0;
		bitDigit = 0;
	}
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d %d %s", &r, &c, bin, 401);
		makeEnc();
		printf("%d ", a + 1);
		decMsg();
		printf("\n");
	}
}