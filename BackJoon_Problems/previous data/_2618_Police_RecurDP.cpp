#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

struct police {
	int x, y;
};

int n, m;
police arr[2000];
int dp[2000][2000];

int Distance(police _a, police _b) {
	return abs(_a.x - _b.x) + abs(_a.y - _b.y);
}

int fun(int x, int y, int cnt) {
	int &reg = dp[x][y];
	if (reg != -1)
		return reg;
	if (cnt == m)
		return reg = 0;
	return reg = min(fun(cnt, y, cnt + 1) + Distance(arr[x], arr[cnt]), fun(cnt, x, cnt + 1) + Distance(arr[y], arr[cnt]));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tmp;
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	m = m + 2;
	arr[0].x = 1;
	arr[0].y = 1;
	arr[1].x = n;
	arr[1].y = n;

	for (int i = 2; i < m; i++)
		cin >> arr[i].x >> arr[i].y;
	tmp = fun(0, 1, 2);

	cout << tmp << endl;
	police A = arr[0];
	police B = arr[1];
	for (int i = 2; i < m; i++) {
		if (i == 2) {
			tmp = tmp - dp[i][0];
		}
		else {
			tmp = dp[i - 1][0] - dp[i][0];
		}

		if (tmp == Distance(arr[i], A)) {
			cout << 1 << endl;
			A = arr[i];
		}
		else {
			cout << 2 << endl;
			B = arr[i];
		}
	}
	return 0;
}