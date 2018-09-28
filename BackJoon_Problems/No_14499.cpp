// 11:20 AM 9/28/2018
// 주사위 굴리기
#include <iostream>
using namespace std;

int N, M, x, y, K, tmp;
int table[32][32];
int dice[8];

struct {
	int dir_x;
	int dir_y;
	int dir_z;
} posited;

int main() {
	posited.dir_x = 3;
	posited.dir_y = 2;
	posited.dir_z = 1;

	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &tmp);
			table[i][j] = tmp;
		}
	}
	
	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);

		if (tmp == 1) {
			// Is possible to going
			if (y >= M - 1) continue;
			y++;

			// set dice direction
			tmp = posited.dir_x;
			posited.dir_x = posited.dir_z;
			posited.dir_z = 7 - tmp;

			// check dice's base
			if (table[x][y] == 0) {
				table[x][y] = dice[tmp];
			}
			else {
				dice[tmp] = table[x][y];
				table[x][y] = 0;
			}

			printf("%d\n", dice[posited.dir_z]);
		}
		
		else if (tmp == 2) {
			// Is possible to going
			if (y <= 0) continue;
			y--;

			// set dice direction
			tmp = 7 - posited.dir_x;
			posited.dir_x = 7 - posited.dir_z;
			posited.dir_z = 7 - tmp;

			// check dice's base
			if (table[x][y] == 0) {
				table[x][y] = dice[tmp];
			}
			else {
				dice[tmp] = table[x][y];
				table[x][y] = 0;
			}

			printf("%d\n", dice[posited.dir_z]);
		}
		
		else if (tmp == 3) {
			// Is possible to going
			if (x <= 0) continue;
			x--;

			// set dice direction
			tmp = 7 - posited.dir_y;
			posited.dir_y = 7 - posited.dir_z;
			posited.dir_z = 7 - tmp;

			// check dice's base
			if (table[x][y] == 0) {
				table[x][y] = dice[tmp];
			}
			else {
				dice[tmp] = table[x][y];
				table[x][y] = 0;
			}

			printf("%d\n", dice[posited.dir_z]);
		}

		else if (tmp == 4) {
			// Is possible to going
			if (x >= N - 1) continue;
			x++;

			// set dice direction
			tmp = posited.dir_y;
			posited.dir_y = posited.dir_z;
			posited.dir_z = 7 - tmp;

			// check dice's base
			if (table[x][y] == 0) {
				table[x][y] = dice[tmp];
			}
			else {
				dice[tmp] = table[x][y];
				table[x][y] = 0;
			}

			printf("%d\n", dice[posited.dir_z]);
		}
	}

	return 0;
}