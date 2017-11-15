#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef struct _POINT {
	int x;
	int y;
} point;

// maximum map size is 1000.
point map[1001];
int mapSize;
int eventCnt;

int minimumDist = 0x7fffffff;

// 
void solve(int, int, int);

// return distance from a to b
int getDistance(int a, int b) {
	return abs(map[a].x - map[b].x) + abs(map[a].y - map[b].y);
}

int main(void) {
	scanf_s("%d %d", &mapSize, &eventCnt);
	map[0].x = map[0].y = 0; // car1 is (0,0)
	map[1].x = map[1].y = mapSize; // car2 is (mapSize, mapSize)
	for (int a = 2;a < eventCnt + 2;a++) {
		scanf_s("%d %d", &map[a].x, &map[a].y); // get Event point
	}
	solve(0, 1, 0); // DFS Search start with index 2 -> mapSize
	printf("%d\n", minimumDist);
	return 0;
}
void solve(int car1idx, int car2idx, int dist) {
	int next = max(car1idx,car2idx) + 1; // find next event index
	if (next >= eventCnt + 2) { // index 0 and 1 is initial car's location. so last location is eventCnt+2
		if (dist < minimumDist) // if it is shortest dist
			minimumDist = dist;
		return;
	}
	solve(next, car2idx, dist + getDistance(car1idx, next)); // car1 was responded
	solve(car1idx, next, dist + getDistance(car2idx, next)); // car2 was responded
}