// ¾çÆÈÀú¿ï
// 3:43 PM 9/19/2018

#include <iostream>
using namespace std;

int num1, num2;
int tmp;
pair<int, int> p[32];
bool valid[16000];

void Validate(int idx, int cur) {
	if (idx > num1) return;

	if (cur > 0) valid[cur] = true;

	for (int i = idx + 1; i < num1; i++) {
		Validate(i, cur + p[i].first);
		Validate(i, cur + p[i].second);
	}
}


int main() {

	scanf("%d", &num1);
	for (int i = 0; i < num1; i++) {
		scanf("%d", &p[i].first);
		p[i].second = -p[i].first;
	}

	for (int i = 0; i < num1; i++) {
		Validate(i, p[i].first);
		Validate(i, p[i].second);
	}

	scanf("%d", &num2);
	for (int i = 0; i < num2; i++) {
		scanf("%d", &tmp);
		if (valid[tmp]) printf("Y ");
		else printf("N ");
	}

	return 0;
}