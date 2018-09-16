// 연구소
// 오후 9:58 2018-09-11 오후 11:29 2018-09-11

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[16][16];
int tmp_map[16][16];
int N, M;
int res, tmp_res;
vector<pair<int, int>> pos;

void spreadVirus(int x, int y) {
	if (tmp_map[x - 1][y] == 0) {
		tmp_map[x - 1][y] = 2;
		spreadVirus(x - 1, y);
	}
	if (tmp_map[x + 1][y] == 0) {
		tmp_map[x + 1][y] = 2;
		spreadVirus(x + 1, y);
	}
	if (tmp_map[x][y - 1] == 0) {
		tmp_map[x][y - 1] = 2;
		spreadVirus(x, y - 1);
	}
	if (tmp_map[x][y + 1] == 0) {
		tmp_map[x][y + 1] = 2;
		spreadVirus(x, y + 1);
	}
}

int main() {

	scanf("%d %d", &N, &M);

	for (int a = 0; a <= M; a++) {
		map[0][a] = 1;
		map[N + 1][a] = 1;
	}

	for (int b = 0; b <= N; b++) {
		map[b][0] = 1;
		map[b][M + 1] = 1;
	}

	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= M; b++) {
			scanf("%d", &map[a][b]);
			if (map[a][b] == 0) pos.push_back(make_pair(a, b));
		}
	}
		

	for (int i = 0; i < pos.size() - 2; i++) {
		for (int j = i + 1; j < pos.size() - 1; j++) {
			for (int k = j + 1; k < pos.size(); k++) {
				pair<int, int> one = pos[i];
				pair<int, int> two = pos[j];
				pair<int, int> three = pos[k];

				for (int i = 0; i <= N + 1; i++) {
					for (int j = 0; j <= M + 1; j++) {
						tmp_map[i][j] = map[i][j];
					}
				}
				
				tmp_map[one.first][one.second] = 1;
				tmp_map[two.first][two.second] = 1;
				tmp_map[three.first][three.second] = 1;

				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= M; j++) {
						if (tmp_map[i][j] == 2)
							spreadVirus(i, j);
					}
				}

				tmp_res = 0;

				for (int a = 1; a <= N; a++) {
					for (int b = 1; b <= M; b++) {
						if (tmp_map[a][b] == 0) tmp_res++;
					}
				}

				res = max(res, tmp_res);
			}
		}
	}

	printf("%d\n", res);
	return 0;
}