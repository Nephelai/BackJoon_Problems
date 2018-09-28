// 2:03 PM 9/27/2018
// 음식물 피하기
#include <iostream>
#include <queue>
using namespace std;

int N, M, K, res, tmp_max;
pair<bool, bool> table[128][128];
// used second value is visited.

pair<int, int> K_p;

void Searching(int x, int y) {
	tmp_max = 0;
	queue<pair<int, int>> queue;
	queue.push({ x, y });
	pair<int, int> tmp;
	while (!queue.empty()) {
		tmp = queue.front();
		queue.pop();
		if (table[tmp.first][tmp.second].second) continue;
		table[tmp.first][tmp.second].second = true;

		tmp_max++;
		
		if (tmp.first > 0 && !table[tmp.first - 1][tmp.second].second && table[tmp.first - 1][tmp.second].first) queue.push({ tmp.first - 1, tmp.second });
		if (tmp.second > 0 && !table[tmp.first][tmp.second - 1].second && table[tmp.first][tmp.second - 1].first) queue.push({ tmp.first, tmp.second - 1 });
		if (tmp.first < N - 1 && !table[tmp.first + 1][tmp.second].second && table[tmp.first + 1][tmp.second].first) queue.push({ tmp.first + 1, tmp.second });
		if (tmp.second < M - 1 && !table[tmp.first][tmp.second + 1].second && table[tmp.first][tmp.second + 1].first) queue.push({ tmp.first, tmp.second + 1 });
	}

	if (tmp_max > res) res = tmp_max;
}


int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &K_p.first, &K_p.second);
		table[K_p.first - 1][K_p.second - 1].first = true;
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (table[x][y].first && !table[x][y].second) Searching(x, y);
		}
	}

	printf("%d\n", res);

	return 0;
}