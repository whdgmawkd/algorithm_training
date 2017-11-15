#define __RETIRE__
#include <stdio.h>
#include <string.h>
void encodeStr(int *data,int len, int r, int c,int arr[][21]) {
	int rMax = r - 1;
	int cMax = c;
	int sw = 1;
	int rI = 0, cI = 0;
	int dataIndex = 0;
	int binDigit = 16; //0x10 : 10000
	int pull = 4;
	while (1) {
		for (int a = 0;a < cMax;a++) {
			if (dataIndex < len) {
				arr[rI][cI] = (data[dataIndex]&binDigit)>>pull;
				binDigit = binDigit >> 1;
				pull--;
				if (binDigit == 0) {
					binDigit = 16;
					dataIndex++;
				}
				if (pull == -1) {
					pull = 4;
				}
			}
			else {
				arr[rI][cI] = 0;
			}
			cI += sw;
		}
		cMax--;
		if (cMax < 0 || rMax < 0)
			break;
		for (int a = 0;a < rMax;a++) {
			if (dataIndex < len) {
				arr[rI][cI] = (data[dataIndex]&binDigit)>>pull;
				binDigit = binDigit >> 1;
				pull--;
				if (binDigit == 0) {
					binDigit = 16;
					dataIndex++;
				}
				if (pull == -1) {
					pull = 4;
				}
			}
			else {
				arr[rI][cI] = 0;
			}
			rI += sw;
		}
		rMax--;
		sw *= -1;
	}
}
int main(void) {
	int n;
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		int arr[21][21] = { 0, };
		int r, c;
		char str[90];
		int strCnv[90] = { 0, };
		scanf_s("%d %d", &r, &c);
		gets_s(str, 90);
		int len = strlen(str);
		for (int a = 0;a < len;a++) {
			if (str[a] == ' ') {
				strCnv[a] = 0;
			}
			else {
				strCnv[a] = str[a] - 'A' + 1;
			}
		}
		encodeStr(strCnv,len, r, c,arr);
		for (int a = 0;a < r;a++) {
			for (int b = 0;b < c;b++) {
				printf("%d ", arr[a][b]);
			}
			printf("\n");
		}
	}
}