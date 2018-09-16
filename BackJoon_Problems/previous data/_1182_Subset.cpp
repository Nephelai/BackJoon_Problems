#include <iostream>
using namespace std;

int N_size, S;
int N[20];
int res;

void backtracking(int _idx, int curr, bool used) {
	if (curr == S && used) {
		res++;

		if (_idx == N_size) return;

		used = true;
		backtracking(_idx + 1, curr + N[_idx], used);
	}
	else {
		if (_idx == N_size) return;
		backtracking(_idx + 1, curr, used);

		used = true;
		backtracking(_idx + 1, curr + N[_idx], used);
	}
}

int main() {

	scanf("%d%d", &N_size, &S);
	for (int i = 0; i < N_size; i++) {
		scanf("%d", &N[i]);
	}
	backtracking(0, 0, false);
	printf("%d\n", res);

	return 0;
}