// ºñ¼ó
// 12:27 AM 9/17/2018
// stack overflow


#include <iostream>
#include <algorithm>
using namespace std;

int map[16][16];
int N, res;

void Position(int x, int y, int n) {
	int newX, newY;

	int tmp_map[16][16];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}

	tmp_map[x][y] = 2;

	newX = x + 1;
	newY = y + 1;
	while (newX < N && newY < N) {
		tmp_map[newX][newY] = 1;
		newX++;
		newY++;
	}

	newX = x - 1;
	newY = y + 1;
	while (newX >= 0 && newY < N) {
		tmp_map[newX][newY] = 1;
		newX--;
		newY++;
	}

	newX = x - 1;
	newY = y - 1;
	while (newX >= 0 && newY >= 0) {
		tmp_map[newX][newY] = 1;
		newX--;
		newY--;
	}

	newX = x + 1;
	newY = y - 1;
	while (newX < N && newY >= 0) {
		tmp_map[newX][newY] = 1;
		newX++;
		newY--;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tmp_map[i][j] == 0) Position(i, j, n + 1);
		}
	}

	res = max(res, n);
	return;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(map[i][j] == 0) Position(i, j, 1);
		}
	}

	printf("%d\n", res);

	return 0;
}