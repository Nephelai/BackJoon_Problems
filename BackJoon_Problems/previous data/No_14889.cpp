// 스타트와 링크
// 오후 9:15 2018-09-11 오후 9:58 2018-09-11
// 재귀를 같이 이용.

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, result1, result2, result;
int map[20][20];
bool visited[20];

void dfs(int t, int n) {

	if (t == 0)	{
		result1 = 0; result2 = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i] && visited[j]) result1 += map[i][j];
				else if (!visited[i] && !visited[j]) result2 += map[i][j];
			}
		}

		result = min(result, abs(result1 - result2));
		return;
	}

	for (int i = n; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(t - 1, i);
			visited[i] = false;
		}
	}
}

int main() {

	cin >> N; result = 99999;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	dfs(N / 2, 0);
	cout << result << endl;

	return 0;

}