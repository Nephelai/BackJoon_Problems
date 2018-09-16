// 리모컨
// 오후 6:38 2018-09-12 오후 7:16 2018-09-12

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, i, k, ans, res;
bool btn[10];

int click(int a) {
	int cnt = 0;
	while (a) {
		if (btn[a % 10]) return -1;
		a /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) scanf("%d", &k), btn[k] = true;

	ans = abs(n - 100);

	if (!btn[0]) ans = min(ans, n + 1);
	for (i = n; i < 1111111; i++) {
		res = click(i);
		if (res > 0) {
			res += i - n;
			ans = min(ans, res);
			break;
		}
	}
	for (i = n; i > 0; i--) {
		res = click(i);
		if (res > 0) {
			res += n - i;
			ans = min(ans, res);
			break;
		}
	}

	printf("%d\n", ans);

	return 0;
}