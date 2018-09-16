// 일곱 난장이
// 오후 4:56 2018-09-11
// 완탐

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
int res, tmp;
int n1, n2;

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &tmp);
		arr.push_back(tmp);
		res += arr[i];
	}

	res -= 100;
	sort(arr.begin(), arr.end());

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (j == i) continue;
			if (arr[i] + arr[j] == res) {
				n1 = i;
				n2 = j;
				break;
			}
		}
		if (n1 != 0) break;
	}

	for (int i = 0; i < 9; i++) {
		if(i != n1 && i != n2) printf("%d\n", arr[i]);
	}

	return 0;
}