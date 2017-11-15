#include <stdio.h>
int n, m, z, t, cnt,avg,newavg,s,e;
int main(void) {
	scanf_s("%d", &t);
	for (int a = 0;a < t;a++) {
		scanf_s("%d %d", &n, &m);
		avg = newavg = (double)m *100 / n;
		s = 0;
		e = 2000000000;
		while (e > s) {
			if (avg >= 99) {
				e = -1;
				break;
			}
			int mid = (s + e) / 2;
			newavg = ((double)m + mid)*100 / (n + mid);
			if (newavg<=avg) {
				s = mid+1;
			}
			else {
				e = mid;
			}
		}
		cnt = e;
		printf("%d\n", cnt);
		cnt = 0;
	}
}