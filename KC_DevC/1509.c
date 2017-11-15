#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char numDigit[7][2] = {" ","¸¸","¾ï","Á¶","°æ","ÇØ","ÀÚ" };
char numDigitDetail[4][2] = { "","½Ê","¹é","Ãµ" };
char numDigitInt[10][2] = { "","ÀÏ","ÀÌ","»ï","»ç","¿À","À°","Ä¥","ÆÈ","±¸" };
char num[50];
char reversedNum[50];

int main(void) {
	int index;
	int digitIndex = 0;
	printf("Input: ");
	scanf("%s", num);
	for (index = strlen(num)-1;index >= 0;index--) {
		if(index%4==0&&num[strlen(num) - index-1]=='1'){
			printf("%c%c",numDigitInt[num[strlen(num) - index-1]-'0'][0],numDigitInt[num[strlen(num) - index-1]-'0'][1]);
		}else if(num[strlen(num) - index-1]!='1'){
			printf("%c%c",numDigitInt[num[strlen(num) - index-1]-'0'][0],numDigitInt[num[strlen(num) - index-1]-'0'][1]);
		}
		if(index%4==0){
			printf("%c%c ",numDigit[index/4][0],numDigit[index/4][1]);
		}else if(num[strlen(num)-index-1]!='0'){
			printf("%c%c",numDigitDetail[index % 4][0],numDigitDetail[index % 4][1]);
		}
	}
}
