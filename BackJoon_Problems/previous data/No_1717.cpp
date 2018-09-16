// 집합의 표현
// 오후 7:21 2018-09-05
// Disjoint Set

#include <iostream>
using namespace std;

int N[1000002], n, m;

int find(int tmp) {
	if (N[tmp] < 0) return tmp;
	N[tmp] = find(N[tmp]);
	return N[tmp];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	N[b] = a;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) N[i] = -1;

	int sel, num1, num2;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &sel, &num1, &num2);
		if (sel == 0) merge(num1, num2);
		else {
			num1 = find(num1);
			num2 = find(num2);
			if (num1 == num2) printf("yes\n");
			else printf("no\n");
		}
	}

	return 0;
}