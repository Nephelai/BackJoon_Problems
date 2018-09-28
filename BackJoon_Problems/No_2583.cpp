// 12:08 PM 9/28/2018
// 영역 구하기
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
pair<int, int> btn, top;
bool table[128][128];
vector<int> res;

void Searching(int x, int y) {
	int tmp_val = 0;
	queue<pair<int, int>> queue;
	queue.push({ x, y });
	pair<int, int> tmp;
	while (!queue.empty()) {
		tmp = queue.front();
		queue.pop();
		if (table[tmp.first][tmp.second]) continue;
		table[tmp.first][tmp.second] = true;
		tmp_val++;

		if (tmp.first > 0 && !table[tmp.first - 1][tmp.second]) queue.push({ tmp.first - 1, tmp.second });
		if (tmp.second > 0 && !table[tmp.first][tmp.second - 1]) queue.push({ tmp.first, tmp.second - 1 });
		if (tmp.first < N - 1 && !table[tmp.first + 1][tmp.second]) queue.push({ tmp.first + 1, tmp.second });
		if (tmp.second < M - 1 && !table[tmp.first][tmp.second + 1]) queue.push({ tmp.first, tmp.second + 1 });
	}

	res.push_back(tmp_val);
}

int main() {
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &btn.first, &btn.second);
		scanf("%d %d", &top.first, &top.second);

		for (int x = btn.first; x < top.first; x++) {
			for (int y = btn.second; y < top.second; y++) {
				table[x][y] = true;
			}
		}
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (!table[x][y]) Searching(x, y);
		}
	}

	printf("%d\n", res.size());
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) printf("%d ", res[i]);

	return 0;
}