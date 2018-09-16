// 암호만들기
// 오후 3:54 2018-08-17
// BackTracking

#include <iostream>
#include <algorithm>
using namespace std;

struct CNT {
	int consonant = 0;
	int vowel = 0;
};
int L, C;
bool isVowel[26];
// 26개의 알파뱃 중에서 0 4 8 14 20이 모음이 된다. a e i o u
char alphas[16], sentence[16];

void backtracking(int pos, int prev, CNT _present) {
	if (pos == L) {
		if (_present.consonant >= 2 && _present.vowel >= 1) printf("%s\n", sentence);
		return;
	}

	CNT tmp;
	for (int i = prev + 1; i<C; i++) {
		sentence[pos] = alphas[i];
		tmp = _present;
		if (isVowel[alphas[i] - 'a']) tmp.vowel++;
		else tmp.consonant++;
		backtracking(pos + 1, i, tmp);
	}
}

int main() {

	CNT rescnt;

	isVowel[0] = isVowel[4] = isVowel[8] = isVowel[14] = isVowel[20] = true;
	scanf("%d%d", &L, &C);
	for (int i = 0; i < C; i++) scanf(" %c", &alphas[i]);
	sort(alphas, alphas + C);
	backtracking(0, -1, rescnt);

	return 0;
}