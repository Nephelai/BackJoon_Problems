// 테트로미노
// 오후 1:01 2018-09-12 오후 6:38 2018-09-12

#include <iostream>
#include <algorithm>
using namespace std;

pair<int, bool> map[512][512];
int N, M, maxi, tmp;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

void dfs(int n, int x, int y, int val) {
	if (n == 0) {
		maxi = max(maxi, val);
		return;
	}

	map[x][y].second = true;
	if (x != 0) {
		if (!map[x - 1][y].second) {
			dfs(n - 1, x - 1, y, val + map[x][y].first);
		}
	}

	if (x != N - 1) {
		if (!map[x + 1][y].second) {
			dfs(n - 1, x + 1, y, val + map[x][y].first);
		}
	}

	if (y != 0) {
		if (!map[x][y - 1].second) {
			dfs(n - 1, x, y - 1, val + map[x][y].first);
		}
	}
		
	if (y != M - 1) {
		if (!map[x][y + 1].second) {
			dfs(n - 1, x, y + 1, val + map[x][y].first);
		}
	}

	map[x][y].second = false;
}

void Exception(int x, int y) {
	int wing = 4;
	int t_min = 987654321;
	int sum = map[x][y].first;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (wing <= 2)
			return;

		if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) {
			wing--;
			continue;
		}
		t_min = min(t_min, map[nextX][nextY].first);
		sum = sum + map[nextX][nextY].first;
	}
	if (wing == 4) {
		sum = sum - t_min;
	}
	maxi = max(maxi, sum);
}



int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j].first);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dfs(4, i, j, 0);
			Exception(i, j);
		}
	}

	printf("%d\n", maxi);

	return 0;
}