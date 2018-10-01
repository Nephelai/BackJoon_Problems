// 1:49 PM 9/29/2018
// 나이트의 이동
#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
const int fx[] = { 1,2,2,1,-1,-2,-2,-1 }, fy[] = { -2,-1,1,2,2,1,-1,-2 };
int t, n, x, y, u, v;
int main() {
	for (scanf("%d", &t); t--;) {
		int dis[300][300] = {};
		scanf("%d%d%d%d%d", &n, &x, &y, &u, &v);
		q.push({ x,y });
		dis[x][y] = 1;
		while (!q.empty()) {
			for (int i = 0; i < 8; i++) {
				int tx = q.front().first + fx[i], ty = q.front().second + fy[i];
				if (tx >= 0 && tx < n&&ty >= 0 && ty < n&&!dis[tx][ty]) {
					dis[tx][ty] = dis[q.front().first][q.front().second] + 1;
					q.push({ tx,ty });
				}
			}
			q.pop();
		}
		printf("%d\n", dis[u][v] - 1);
	}
	return 0;
}