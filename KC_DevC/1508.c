#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char decKey[26];
char encStr[100];

int main(void){
	int a,b;
	char tmp;
	int engSum=0;
	int decSum=0;
	printf("Decryption KEY: ");
	scanf("%s",decKey);
	fflush(stdin);
	printf("Encrypted String: ");
	gets(encStr);
	system("cls");
	for(a='a';a<='z';a++){
		engSum+=a;
	}
	for(a=0;a<26;a++){
		decSum+=decKey[a];
	}
	if(engSum!=decSum||strlen(decKey)<26){
		printf("Decyption KEY Error!!\n");
		return 0;
	}
	for(a=0;a<strlen(encStr);a++){
		if(encStr[a]==32){ // Space
			printf(" ");
		}
		else if(encStr[a]<'a'){ // Big alphabet A-Z
			tmp=encStr[a]+32;
			for(b=0;b<26;b++){
				if(decKey[b]==tmp){
					printf("%c",'A'+b);
					break;
				}
			}
		}
		else{ // Small alphabet a-z
			tmp=encStr[a];
			for(b=0;b<26;b++){
				if(decKey[b]==tmp){
					printf("%c",'a'+b);
					break;
				}
			}
		}
	}
	printf("\n");
	return 0;
}
