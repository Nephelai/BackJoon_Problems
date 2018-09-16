// 숫자카드
// 오전 11:38 2018-07-30
// Binary Search

#include <iostream>
#include <set>
using namespace std;

set<int> dt;
int _size, tmp_num;

int main() {
	scanf("%d", &_size);
	while (_size--) {
		scanf("%d", &tmp_num);
		dt.insert(tmp_num);
	}
	scanf("%d", &_size);
	while (_size--) {
		scanf("%d", &tmp_num);
		if (dt.find(tmp_num) == dt.end())
			printf("0 ");
		else printf("1 ");
	}
	return 0;
}