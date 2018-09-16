// Âï±â
// ¿ÀÀü 1:08 2018-09-12

#include <iostream>
#include <algorithm>
using namespace std;

char Adrian[128];
char Bruno[128];
char Goran[128];

int N, a, b, c, res;
char tmp;

int main() {

	for (int i = 0; i < 100; i += 3) {
		Adrian[i] = 'A';
		Adrian[i + 1] = 'B';
		Adrian[i + 2] = 'C';
	}

	for (int i = 0; i < 100; i += 4) {
		Bruno[i] = 'B';
		Bruno[i + 1] = 'A';
		Bruno[i + 2] = 'B';
		Bruno[i + 3] = 'C';
	}

	for (int i = 0; i < 100; i += 6) {
		Goran[i] = 'C';
		Goran[i + 1] = 'C';
		Goran[i + 2] = 'A';
		Goran[i + 3] = 'A';
		Goran[i + 4] = 'B';
		Goran[i + 5] = 'B';
	}

	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%c", &tmp);
		if (tmp == Adrian[i]) a++;
		if (tmp == Bruno[i]) b++;
		if (tmp == Goran[i]) c++;
	}
	res = max(a, b);
	res = max(res, c);

	printf("%d\n", res);
	if (res == a) printf("Adrian\n");
	if (res == b) printf("Bruno\n");
	if (res == c) printf("Goran\n");

	return 0;
}