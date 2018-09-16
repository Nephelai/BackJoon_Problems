// ���� �ڸ���
// ���� 8:43 2018-08-07
// Binary Search

#include <iostream>
#include <algorithm>
using namespace std;

// ������ ����..
// ������ long long���� �ΰ� low�� 1, high�� -1�� �ʱⰪ�� ����־���Ѵ�.
// 1 1 1�� ���� ������..

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