#include <iostream>
#include <cstring>
#include <set>
using namespace std;
#define MAX 1024

int p[MAX];
int N, M;
int tmp_a, tmp_b;
set<int> res;

int find(int n) {
	if (p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}

int main() {
	memset(p, -1, sizeof(p));
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &tmp_a, &tmp_b);
		merge(tmp_a, tmp_b);
	}
	for (int i = 1; i <= N; i++) {
		res.insert(find(i));
	}
	printf("%d\n", res.size());

	return 0;
}