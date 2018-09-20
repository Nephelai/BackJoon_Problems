// 케빈 베이컨의 6단계 법칙
// 10:18 PM 9/20/2018

#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_V = 20000;
const int INF = 1000000000; // 절대 나올 수 없는 경로값
typedef pair<int, int> P;

int main() {
	int V, E, K, res, tmp, res_id;
	res = INT_MAX;
	vector<P> adj[MAX_V]; // (이어진 정점 번호, 거리)
	scanf("%d %d", &V, &E);
	// K 시작점.

	for (int i = 0; i<E; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		// weight = 1
		adj[u - 1].push_back(P(v - 1, 1));
		adj[v - 1].push_back(P(u - 1, 1));
	}

	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);
	bool visited[MAX_V] = { 0 };
	priority_queue<P, vector<P>, greater<P>> PQ;

	// 다익스트라 알고리즘
	for (K = 0; K < V; K++) {
		tmp = 0;
		fill(dist, dist + MAX_V, INF);
		fill(visited, visited + MAX_V, false);

		dist[K] = 0; // 시작점으로의 거리는 0
		PQ.push(P(0, K)); // 시작점만 PQ에 넣고 시작
		while (!PQ.empty()) { // PQ가 비면 종료
			int curr;
			do {
				curr = PQ.top().second;
				PQ.pop();
			} while (!PQ.empty() && visited[curr]); // curr가 방문한 정점이면 무시
													// 더 이상 방문할 수 있는 정점이 없으면 종료
			if (visited[curr]) break;

			visited[curr] = true; // 방문
			for (auto &p : adj[curr]) {
				int next = p.first, d = p.second;
				// 거리가 갱신될 경우 PQ에 새로 넣음
				if (dist[next] > dist[curr] + d) {
					dist[next] = dist[curr] + d;
					PQ.push(P(dist[next], next));
				}
			}
		}

		for (int i = 0; i<V; i++) {
			tmp += dist[i];
		}

		if (tmp < res) {
			res = tmp;
			res_id = K + 1;
		}
	}
	
	printf("%d\n", res_id);
	// 결과

	return 0;
}