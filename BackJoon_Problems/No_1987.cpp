// ¾ËÆÄºª
// 11:37 PM 9/16/2018

#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
int res;

char map[32][32];

void alphabet(int x, int y, int n, int t) {
	int comp_c;
	res = max(res, n);

	if (x < R - 1) {
		comp_c = map[x + 1][y] - 'A';
		comp_c = 1 << comp_c;
		if((t & comp_c) == 0) alphabet(x + 1, y, n + 1, t | comp_c);
	}

	if (x > 0) {
		comp_c = map[x - 1][y] - 'A';
		comp_c = 1 << comp_c;
		if ((t & comp_c) == 0) alphabet(x - 1, y, n + 1, t | comp_c);
	}

	if (y < C - 1) {
		comp_c = map[x][y + 1] - 'A';
		comp_c = 1 << comp_c;
		if ((t & comp_c) == 0) alphabet(x, y + 1, n + 1, t | comp_c);
	}

	if (y > 0) {
		comp_c = map[x][y - 1] - 'A';
		comp_c = 1 << comp_c;
		if ((t & comp_c) == 0) alphabet(x, y - 1, n + 1, t | comp_c);
	}
	return;
}


int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	int start = map[0][0] - 'A';
	start = 1 << start;
	alphabet(0, 0, 1, start);

	printf("%d\n", res);

	return 0;
}