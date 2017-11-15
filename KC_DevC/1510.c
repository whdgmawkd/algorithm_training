#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a,b,c;
int n;

int main(void){
	int time=0;
	printf("Input: "); 
	scanf("%d",&n);
	if(n>10000){
		printf("Error!\n");
		return -1;
	}
	while(n>0){
		if(a==0&&n>0){
			n--;
			a=1;
		}
		if(b==0&&n>0){
			n--;
			b=3;
		}
		if(c==0&&n>0){
			n--;
			c=4;
		}
		a--,b--,c--;
		time++;
	}
	printf("%d\n",time);
	return 0;
}
