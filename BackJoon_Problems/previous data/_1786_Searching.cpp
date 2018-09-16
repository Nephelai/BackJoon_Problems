#include <iostream>
#include <string>
#include <vector>
#define MAX 1000000
using namespace std;

string S, W;
int fail[MAX];

int main() {
	getline(cin, S);
	getline(cin, W);

	
	for (int i = 1, j = 0; i < W.size(); i++) {
		while (j > 0 && W[i] != W[j]) j = fail[j - 1];
		if (W[i] == W[j]) fail[i] = ++j;
	}

	vector<int> result;
	for (int i = 0, j = 0; i < S.size(); i++) {
		// 현재 글자가 불일치하면 fail 값을 계속 따라감
		while (j > 0 && S[i] != W[j]) j = fail[j - 1];
		// 현재 글자가 일치
		if (S[i] == W[j]) {
			// W를 S[i:i+M-1]에서 찾음
			if (j == W.size() - 1) {
				// i=0부터 시작한다면 i-M+1. 문제 조건에 따라 1을 더함
				result.push_back(i - W.size() + 2);
				// 찾지 못한 것처럼 j를 이동시키면 됨
				j = fail[j];
			}
			else j++;
		}
	}

	// 결과 출력
	printf("%d\n", result.size());
	for (int i : result)
		printf("%d ", i);

	printf("\n");
	return 0;
}