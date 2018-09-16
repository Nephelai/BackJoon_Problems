// 미친로봇
// 오후 12:11 2018-09-12 오후 12:58 2018-09-12

#include <iostream>
using namespace std;

double probability[4];
int N;

double res;

bool map[32][32];

void dfs(int x, int y, double p, int n) {
	if (map[x][y]) {
		res += p;
		return;
	}
	else map[x][y] = true;
	
	if (n == 0) {
		map[x][y] = false;
		return;
	}

	dfs(x + 1, y, p * probability[0], n - 1);

	dfs(x - 1, y, p * probability[1], n - 1);

	dfs(x, y - 1, p * probability[2], n - 1);

	dfs(x, y + 1, p * probability[3], n - 1);

	map[x][y] = false;
}


int main() {
	scanf("%d", &N);
	for (int i = 0; i < 4; i++) {
		scanf("%lf", &probability[i]);
		probability[i] /= 100;
	}

	dfs(16, 16, 1, N);

	printf("%.9lf\n", 1 - res);

	return 0;
}