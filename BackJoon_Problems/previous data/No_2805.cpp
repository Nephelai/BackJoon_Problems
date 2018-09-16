// 나무자르기
// 오후 2:36 2018-07-30
// Binary Search

#include <iostream>
#define MAX 1e9
using namespace std;

int N, M;
int h[1000006];
long long ans;
int low, high, mid;

int main() {
	scanf("%d%d", &N, &M);
	low = 0;
	high = MAX;
	for (int i = 0; i < N; i++) scanf("%d", &h[i]);
	while (low <= high) {
		mid = (low + high) / 2;
		ans = 0;
		for (int i = 0; i < N; i++) {
			if (h[i] > mid) ans += h[i] - mid;
		}
		if (ans < M) high = mid - 1;
		else low = mid + 1;
	}

	printf("%d\n", high);
	return 0;
}