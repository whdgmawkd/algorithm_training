#include <stdio.h>

int n;

bool isPrime(int num) {
	for (int a = 2;a*a <= num;a++) { // Big-O(sqrt(num))
		if (num%a == 0)
			return false;
	}
	return true;
}

int primeSum() {
	int sum = 0;
	int primeCnt = 0;
	int num = 2;
	while (primeCnt < n) {
		if (isPrime(num)) {
			sum += num;
			printf("%d %d\n", primeCnt, num);
			primeCnt++;
		}
		num++;
	}
	return num-1;
}

int main(void) {
	scanf_s("%d", &n);
	printf("%d\n", primeSum());
	return 0;
}