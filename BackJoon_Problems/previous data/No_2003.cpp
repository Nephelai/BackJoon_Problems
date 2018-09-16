// 수들의 합2
// 오전 11:55 2018-08-06
// Two Pointer
#include <iostream>
using namespace std;

int A[10004];
int N, M, tmp, res, first, last;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	tmp = A[0];
	while (last != N) {
		if (tmp < M) {
			last++;
			tmp += A[last];
		}
		else if (tmp > M) {
			tmp -= A[first];
			first++;
		}
		else {
			res++;
			last++;
			tmp += A[last];
		}
	}
	printf("%d\n", res);
	return 0;
}