// ºñ¼ó
// 12:27 AM 9/17/2018
// stack overflow


#include <iostream>
#include <algorithm>
using namespace std;

int n, chess[11][11], check[50], ans, ans2;

void func1(int r, int c, int l) {
	if (ans < l)
		ans = l;
	if (r >= n)	return;

	if (c >= n) {
		r++;
		if (r % 2)	c = 1;
		else c = 0;
	}

	if (chess[r][c]) {
		if (!check[r + c] && !check[25 + r - c]) {
			check[r + c] = 1;
			check[25 + r - c] = 1;
			func1(r, c + 2, l + 1);
			check[r + c] = 0;
			check[25 + r - c] = 0;
		}
	}
	func1(r, c + 2, l);
}

void func2(int r, int c, int l) {
	if (ans2 < l)
		ans2 = l;
	if (r >= n)	return;

	if (c >= n) {
		r++, c = 0;
		if (r % 2)	c = 0;
		else c = 1;
	}

	if (chess[r][c]) {
		if (!check[r + c] && !check[25 + r - c]) {
			check[r + c] = 1;
			check[25 + r - c] = 1;
			func2(r, c + 2, l + 1);
			check[r + c] = 0;
			check[25 + r - c] = 0;
		}
	}

	func2(r, c + 2, l);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &chess[i][j]);

	func1(0, 0, 0);
	func2(0, 1, 0);

	printf("%d\n", ans + ans2);

	return 0;
}
