#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int m,n;

int numCnt[10];
char tmp[5];

int main(void){
	int a,b;
	printf("???: ");
	scanf("%d %d",&m,&n);
	system("cls");
	printf("????(01) ??(???) ???(????????)\n");
	printf("==============================\n");
	if(m<1||m>1000||n<1||m>1000||m>n){
		printf("?? ??\n");
		return -1;
	}
	for(a=m;a<=n;a++){
		itoa(a,tmp,10);
		for(b=0;b<3;b++){
			numCnt[tmp[b]-'0']++;
		}
	}
	for(a=0;a<10;a+=2){
		printf("%d: %d?\t%d %d?\n",a,numCnt[a],a+1,numCnt[a+1]);
	}
	return 0;
	
}
