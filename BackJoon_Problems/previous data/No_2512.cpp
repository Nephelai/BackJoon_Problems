// 예산
// 오후 9:53 2018-08-08
// Binary Search

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int country[100004];
int low, high, mid, sum;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &country[i]);
		high = max(high, country[i]);
	}
	scanf("%d", &M);

	while (low <= high) {
		sum = 0;
		mid = (low + high) / 2;
		for (int i = 0; i < N; i++) {
			if (country[i] < mid) sum += country[i];
			else sum += mid;
		}
		if (sum <= M) low = mid + 1;
		else high = mid - 1;
	}

	printf("%d\n", high);

	return 0;
}