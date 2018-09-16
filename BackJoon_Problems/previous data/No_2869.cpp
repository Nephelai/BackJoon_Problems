// 달팽이는 올라가고 싶다
// 오후 5:09 2018-08-08
// With Math.
#include <iostream>
using namespace std;

int A, B, V;

int main() {
	scanf("%d%d%d", &A, &B, &V);
	printf("%d\n", (V - A - 1) / (A - B) + 2);

	return 0;
}

// Binary Search
//#include <iostream>
//using namespace std;
//
//int A, B, V, tmp, low, high, mid;
//
//int main() {
//	scanf("%d%d%d", &A, &B, &V);
//
//	high = V;
//
//	while (low <= high) {
//		mid = (low + high) / 2;
//		tmp = (mid * (A - B)) + A;
//		if (tmp <= V) {
//
//			low = mid + 1;
//		}
//		else high = mid - 1;
//	}
//
//	printf("%d\n", mid);
//	return 0;
//}