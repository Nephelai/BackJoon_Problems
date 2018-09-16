#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> d;
pair<int, int> p;
int t[201];
long long tmp_d, tmp_p;

int Comb(int x, int y) {
	// x > y
	fill(&t[0], &t[0] + x + 1, 1);
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if(t[j] += t[j - 1] > 1000007)
				t[j] = (t[j] + t[j - 1]) % 1000007;
			else
				t[j] += t[j - 1];
		}
	}

	return t[x];
}


int main() {

	// first°¡ xÃà
	scanf("%d%d", &d.first, &d.second);
	scanf("%d%d", &p.first, &p.second);

	d.first -= p.first;
	d.second -= p.second;

	p.first -= 1;
	p.second -= 1;

	if (p.first == 0 && p.second == 0)
		tmp_p = 1;
	else {
		if (p.first > p.second)
			tmp_p = Comb(p.first, p.second);
		else
			tmp_p = Comb(p.second, p.first);
	}

	if (d.first == 0 && d.second == 0)
		tmp_d = 1;
	else {
		if (d.first > d.second)
			tmp_d = Comb(d.first, d.second);
		else
			tmp_d = Comb(d.second, d.first);
	}

	printf("%lld\n", (tmp_d * tmp_p) % 1000007);

	return 0;
}