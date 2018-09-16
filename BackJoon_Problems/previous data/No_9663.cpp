// N-Queen
// ¿ÀÈÄ 10:11 2018-09-12
// Using BackTraking.

#include <iostream>
using namespace std;

int n, res;
int col[16];


bool Promising(int _idx) {
	bool checked = true;
	int p = 1;

	while (p < _idx && checked)	{
		if (col[_idx] == col[p] || abs(col[_idx] - col[p]) == _idx - p)
			checked = false;
		p++;
	}

	return checked;
}


void Queens(int _idx) {
	if (Promising(_idx)) {
		if (_idx == n) res++;
		else {
			for (int i = 1; i <= n; i++) {
				col[_idx + 1] = i;
				Queens(_idx + 1);
			}
		}
	}
}

int main() {

	scanf("%d", &n);

	Queens(0);

	printf("%d\n", res);

	return 0;
}