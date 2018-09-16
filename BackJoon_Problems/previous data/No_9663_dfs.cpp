// N-Queen
// ¿ÀÈÄ 7:16 2018-09-12

#include <iostream>
using namespace std;

int tmp_map[16][16];
int n, res;

void FindQueen(int x, int y, int cnt, int _map[][16]) {

	if (cnt == n) {
		res++;
		return;
	}

	if (cnt > n) return;

	int map[16][16];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = _map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (i != x) map[i][y] = -1;
		if (i != y) map[x][i] = -1;

		if (i != 0) {
			if (x + i < n && y + i < n) map[x + i][y + i] = -1;
			if (x + i < n && y - i >= 0) map[x + i][y - i] = -1;
			if (x - i >= 0 && y + i < n) map[x - i][y + i] = -1;
			if (x - i >= 0 && y - i >= 0) map[x - i][y - i] = -1;
		}
	} 

	int t = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) t++;
		}
	}

	if (t + cnt < n) return;

	for (int i = 0; i < n; i++) {
		if (i == x) continue;
		for (int j = 0; j < n; j++) {
			if (j == y) continue;
			if (map[i][j] == 0) {
				map[i][j] = 1;
				FindQueen(i, j, cnt + 1, map);
			}
		}
	}

	return;
}


int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		tmp_map[i][0] = 1;
		FindQueen(i, 0, 1, tmp_map);
	}

	printf("%d\n", res);

	return 0;
}