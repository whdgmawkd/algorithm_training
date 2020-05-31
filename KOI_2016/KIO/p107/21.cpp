#include <stdio.h>
#include <algorithm>

using namespace std;

int gift[16];
int n;

//first second third
int f, s, t;

void solve(int index, int a, int b, int c);

int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", &gift[a]);
	}
	sort(gift, gift + n, [](int a, int b) {return a > b;});
	solve(0, 0, 0, 0);
	printf("%d %d %d\n", f, s, t);
	return 0;
}

void solve(int index, int a, int b, int c) {
	if (index < n) {
		solve(index + 1, a, b, c + gift[index]);
		solve(index + 1, a, b + gift[index], c);
		solve(index + 1, a + gift[index], b, c);
	}
	else if (a>=b && b>=c)
	{
		f = a;
		s = b;
		t = c;
	}
}