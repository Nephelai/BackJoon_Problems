// 숫자카드 2
// 오전 12:01 2018-08-09
// multiset..
// how about maps

//#include <iostream>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//map<int, int> card;
//map<int, int>::iterator iter;
//int N, M, tmp, mini, maxi;
//
//int main() {
//	scanf("%d", &N);
//	mini = 987654321;
//	maxi = -987654321;
//	while (N--) {
//		scanf("%d", &tmp);
//		iter = card.find(tmp);
//		if (card.end() == iter) {
//			card.insert(map< int, int >::value_type(tmp, 1));
//			mini = min(mini, tmp);
//			maxi = max(maxi, tmp);
//		}
//
//		else iter->second++;
//	}
//	scanf("%d", &M);
//	while (M--)	{
//		scanf("%d", &tmp);
//		if (tmp < mini && tmp > maxi) printf("0");
//		else {
//			iter = card.find(tmp);
//			if (card.end() == iter) printf("0");
//			else printf("%d", iter->second);
//		}
//		printf(" ");
//	}
//	printf("\n");
//	return 0;
//}

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int m;
vector<int> v;
int cnt(int k)
{
	return (upper_bound(v.begin(), v.end(), k) - v.begin()) - (lower_bound(v.begin(), v.end(), k) - v.begin());

}
int main()
{
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i<n; ++i) {
		int x;
		scanf("%d", &x);
		v[i] = x;
	}
	sort(v.begin(), v.end());
	scanf("%d", &m);
	for (int i = 0; i<m; ++i) {
		int x;
		scanf("%d", &x);
		printf("%d ", cnt(x));
	}

}