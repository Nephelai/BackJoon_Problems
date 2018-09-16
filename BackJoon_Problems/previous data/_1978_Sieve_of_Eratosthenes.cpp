// Sieve of Eratosthenes
// 에라토스테네스의 체
#include <iostream>
#include <cstring>
using namespace std;

int prime_size;
int arr[100];
int prime_count;

struct Node {
	int val;
	bool checked = false;
};


int main() {

	Node arr[100];

	scanf("%d", &prime_size);

	for (int i = 0; i < prime_size; i++) {
		scanf("%d", &arr[i].val);
	}

	for (int i = 0; i < prime_size; i++) {
		if (arr[i].val == 1)
			continue;
		if (!arr[i].checked) {
			arr[i].checked = true;

			for (int tmp = 1; tmp < prime_size; tmp++) {
				if (arr[tmp].val % arr[i].val == 0)
					arr[tmp].checked = true;
			}
			prime_count++;
		}
	}

	printf("%d\n", prime_count);

	return 0;
}