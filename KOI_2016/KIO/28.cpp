#include <stdio.h>
#include <algorithm>

using namespace std;

int p, f, pp[100], fp[100], pv[100], mh = 0x7fffffff;

void g(int pt, int ft, int h) {
	if (ft == f) {
		mh = min(mh, h);
		return;
	}
	for (int a = 1;a <= p;a++) {
		if (pv[a] == 0) {
			pv[a] = 1;
			h += abs(pp[a] - fp[ft + 1]);
			g(a, ft + 1, h);
			h -= abs(pp[a] - fp[ft + 1]);
			pv[a] = 0;
		}
	}
}

int main(void) {
	scanf_s("%d %d", &p, &f);
	for (int a = 1;a <= p;a++) {
		scanf_s("%d", pp + a);
	}
	for (int a = 1;a <= f;a++) {
		scanf_s("%d", fp + a);
	}
	g(0, 0, 0);
	printf("%d\n", mh);
	return 0;
}