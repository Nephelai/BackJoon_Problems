// 수 찾기
// 오후 12:30 2018-07-29
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
	while (_size--)	{
		scanf("%d", &tmp_num);
		if(dt.find(tmp_num) == dt.end())
			printf("0\n");
		else printf("1\n");
	}
	return 0;
}