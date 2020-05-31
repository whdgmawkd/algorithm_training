#include <stdio.h>

const int MAXIMUM = 40;

int current;
int target;

int count = 40;

// changeTemp(val,cnt): check if val equls target.
int changeTemp(int, int);

int main(void) {
	scanf_s("%d %d", &current, &target);
	changeTemp(current, 0);
	printf("%d\n", count);
	return 0;
}

int changeTemp(int val, int cnt) {
	if (cnt > MAXIMUM)
		return -1;
	if (val == target && cnt < count) {
		count = cnt;
		return 0;
	}
	if (val > target) {
		if (val - target >= 10)
			changeTemp(val - 10, cnt + 1);
		else if (val - target >= 5)
			changeTemp(val - 5, cnt + 1);
		else
			changeTemp(val - 1, cnt + 1);
	}
	else if (val < target) {
		if (target - val >= 10)
			changeTemp(val + 10, cnt + 1);
		else if (target - val >= 5)
			changeTemp(val + 5, cnt + 1);
		else
			changeTemp(val + 1, cnt + 1);
	}
	return 9;
}