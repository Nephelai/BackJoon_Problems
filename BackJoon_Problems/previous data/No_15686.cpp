// 치킨 배달
// 오후 11:29 2018-09-11 오전 1:06 2018-09-12

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 987654321
using namespace std;

int table[128][16];
int N, M, tmp;
int tmp_min, tmp_res, res;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<int> checked;
vector<int>::iterator iter;

void dfs(int n, int m) {
	if (n == 0) {
		tmp_res = 0;
		for (int i = 0; i < home.size(); i++) {
			iter = checked.begin();
			tmp_min = MAX;
			while (iter != checked.end()) {
				tmp_min = min(tmp_min, table[i][*iter]);
				iter++;
			}
			tmp_res += tmp_min;
		}
		res = min(res, tmp_res);
		return;
	}

	for (int i = m; i < chicken.size(); i++) {
		checked.push_back(i);
		dfs(n - 1, i + 1);
		checked.pop_back();
	}
}


int main() {
	res = MAX;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			if (tmp == 1) home.push_back(make_pair(i, j));
			else if (tmp == 2) chicken.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < home.size(); i++) {
		for (int j = 0; j < chicken.size(); j++) {
			table[i][j] = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
		}
	}

	dfs(M, 0);

	printf("%d\n", res);
	return 0;
}