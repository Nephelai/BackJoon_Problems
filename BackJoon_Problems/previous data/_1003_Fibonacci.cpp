#include <iostream>
using namespace std;

int T, tmp;
struct Node {
	int _zero = 0;
	int _one = 0;
};

int main() {

	scanf("%d", &T);
	
	Node sp[40];

	sp[0]._one = 0;
	sp[0]._zero = 1;

	sp[1]._one = 1;
	sp[1]._zero = 0;

	while (T--) {
		scanf("%d", &tmp);
		for (int i = 2; i <= tmp; i++) {
			sp[i]._one = sp[i - 1]._one + sp[i - 2]._one;
			sp[i]._zero = sp[i - 1]._zero + sp[i - 2]._zero;
		}

		printf("%d %d\n", sp[tmp]._zero, sp[tmp]._one);
	}
	return 0;
}