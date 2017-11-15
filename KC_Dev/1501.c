#include <stdio.h>

int RoomState[101];
int RoomCnt;

int printRoom(int index);
int ChangeState(int index);
int getOpenedRoomCnt();
void printFirst();

int main(void) {
	printf("입력: ");
	scanf_s("%d", &RoomCnt);
	printFirst();
	if (RoomCnt > 100 || RoomCnt < 5) {
		printf("입력 오류\n");
		return 1;
	}
	for (int a = 1;a <= RoomCnt;a++) {
		ChangeState(a);
		printRoom(a);
	}
	printf("열린 문은 %d개 입니다.\n",getOpenedRoomCnt());
	return 0;
}

void printFirst() {
	system("cls");
	printf("참가번호(01) 성명(박종흠) 학교명(용인정보고등학교)\n");
	printf("==========================================\n");
}

int ChangeState(int index) {
	for (int a = 0;a <= RoomCnt;a += index) {
		if (RoomState[a] == 0) {
			RoomState[a] = 1;
		}
		else {
			RoomState[a] = 0;
		}
	}
	return 0;
}

int printRoom(int index) {
	for (int a = 1;a <= RoomCnt;a++) {
		if (RoomState[a] == 0) {
			printf("c ");
		}
		else {
			printf("o ");
		}
	}
	printf("\t--%d배수\n", index);
	return 0;
}

int getOpenedRoomCnt() {
	int Cnt = 0;
	for (int a = 1;a*a <= RoomCnt;a++) {
		if (a*a <= RoomCnt)
			Cnt++;
	}
	return Cnt;
}