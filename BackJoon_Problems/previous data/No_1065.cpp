// �Ѽ�
// ���� 5:48 2018-09-11
// �ܼ� �ݺ�

#include <iostream>
using namespace std;

int c_size, val, cnt;
int tmp_n, tmp1, tmp2;

int main() {
	scanf("%d", &val);
	
	for (int num = 1; num <= val; num++) {
		if (num < 100) cnt++;
		else {
			tmp1 = num % 10;
			tmp_n = num / 10;
			tmp2 = tmp_n % 10;
			tmp_n = tmp_n / 10;

			if (tmp1 - tmp2 == tmp2 - tmp_n) cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}