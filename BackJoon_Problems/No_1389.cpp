// �ɺ� �������� 6�ܰ� ��Ģ
// 10:18 PM 9/20/2018

#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_V = 20000;
const int INF = 1000000000; // ���� ���� �� ���� ��ΰ�
typedef pair<int, int> P;

int main() {
	int V, E, K, res, tmp, res_id;
	res = INT_MAX;
	vector<P> adj[MAX_V]; // (�̾��� ���� ��ȣ, �Ÿ�)
	scanf("%d %d", &V, &E);
	// K ������.

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

	// ���ͽ�Ʈ�� �˰���
	for (K = 0; K < V; K++) {
		tmp = 0;
		fill(dist, dist + MAX_V, INF);
		fill(visited, visited + MAX_V, false);

		dist[K] = 0; // ������������ �Ÿ��� 0
		PQ.push(P(0, K)); // �������� PQ�� �ְ� ����
		while (!PQ.empty()) { // PQ�� ��� ����
			int curr;
			do {
				curr = PQ.top().second;
				PQ.pop();
			} while (!PQ.empty() && visited[curr]); // curr�� �湮�� �����̸� ����
													// �� �̻� �湮�� �� �ִ� ������ ������ ����
			if (visited[curr]) break;

			visited[curr] = true; // �湮
			for (auto &p : adj[curr]) {
				int next = p.first, d = p.second;
				// �Ÿ��� ���ŵ� ��� PQ�� ���� ����
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
	// ���

	return 0;
}