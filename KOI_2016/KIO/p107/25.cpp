#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef struct _POINT {
	int x;
	int y;
} point;

int refuelCnt;
int maximumRefuel;
point location[11];
bool isSupplied[11];
int minimumDistance = 987654321;

// return distance from p1 to p2
int getDistance(point, point);
void findFuelAmount(int, int, int);
void input();

int main(void) {
	input();
	isSupplied[0] = true;
	findFuelAmount(0, 0, 0);
	printf("sqrt : %.f\n", sqrt(minimumDistance));
	printf("%.f\n", ceil(sqrt(minimumDistance)/10));
	return 0;
}

void findFuelAmount(int point, int count, int distance) {
	if (count == maximumRefuel) {
		distance = max(distance, getDistance(location[point], location[refuelCnt + 1]));
		printf("dist : %d\n", distance);
		if (distance < minimumDistance) {
			printf("dist_min : %d\n", distance);
			minimumDistance = distance;
		}
		return;
	}
	for (int a = 0;a <= refuelCnt + 1;a++) {
		if (!isSupplied[a]) {
			isSupplied[a] = true;
			findFuelAmount(a, count + 1, max(distance, getDistance(location[point], location[a])));
			isSupplied[a] = false;
		}
	}
}

int getDistance(point p1, point p2) {
	printf("x : %d %d y : %d %d\n", p1.x, p1.y, p2.x, p2.y);
	printf("getDist: %d\n", ((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
	return ((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void input(void) {
	scanf_s("%d %d", &refuelCnt, &maximumRefuel);
	location[0].x = location[0].y = 0;
	for (int a = 1;a <= refuelCnt;a++) {
		scanf_s("%d %d", &location[a].x, &location[a].y);
	}
	location[refuelCnt + 1].x = location[refuelCnt + 1].y = 10000;
}
