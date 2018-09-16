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
		// ���� ���ڰ� ����ġ�ϸ� fail ���� ��� ����
		while (j > 0 && S[i] != W[j]) j = fail[j - 1];
		// ���� ���ڰ� ��ġ
		if (S[i] == W[j]) {
			// W�� S[i:i+M-1]���� ã��
			if (j == W.size() - 1) {
				// i=0���� �����Ѵٸ� i-M+1. ���� ���ǿ� ���� 1�� ����
				result.push_back(i - W.size() + 2);
				// ã�� ���� ��ó�� j�� �̵���Ű�� ��
				j = fail[j];
			}
			else j++;
		}
	}

	// ��� ���
	printf("%d\n", result.size());
	for (int i : result)
		printf("%d ", i);

	printf("\n");
	return 0;
}