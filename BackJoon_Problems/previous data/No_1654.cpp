// 랜선 자르기
// 오전 8:43 2018-08-07
// Binary Search

#include <iostream>
#include <algorithm>
using namespace std;

// 쓰레기 문제..
// 변수를 long long으로 두고 low를 1, high를 -1로 초기값을 잡아주어야한다.
// 1 1 1의 예시 때문에..

long long K, N, tmp, low = 1, high = -1, mid, res;
long long len[10004];
int main() {
	scanf("%d%d", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%d", &len[i]);
		high = max(high, len[i]);
	}
	while (low <= high)	{
		mid = (low + high) / 2;
		tmp = 0;
		for (int i = 0; i < K; i++) tmp += (len[i] / mid);
		//if (tmp >= N && mid > res) res = mid;
		if (tmp < N) high = mid - 1;
		else {
			res = mid;
			low = mid + 1;
		}
	}

	printf("%d\n", res);
	return 0;
}