#include <iostream>
using namespace std;

bool arr[100000];
int idx;
int K, N;
int cnt;
bool lighton;

void Switching(int _idx) {
	for (int i = _idx; i < _idx + K; i++) {
		if (arr[i])
			arr[i] = false;
		else
			arr[i] = true;
	}
}

int main() {
	freopen("in.in", "r", stdin);
	freopen("out.txt", "w", stdout);


	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &idx);
		arr[i] = idx;
	}

	for (int i = 0; i <= N - K; i++) {
		if (arr[i]) {
			Switching(i);
			cnt++;
		}
	}

	for (int i = N - K; i < N; i++) {
		if (arr[i]) {
			lighton = true;
			break;
		}
	}

	if (lighton) printf("Insomnia\n");
	else printf("%d\n", cnt);


	return 0;
}