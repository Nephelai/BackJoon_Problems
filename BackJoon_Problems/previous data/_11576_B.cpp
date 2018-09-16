#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int a, b;
int num_size, tmp;
unsigned int num;
stack<int> tmp_st;

int main() {
	scanf("%d%d", &a, &b);
	scanf("%d", &num_size);
	num_size--;

	while (num_size != -1) {
		scanf("%d", &tmp);
		num += tmp*pow(a,num_size);
		num_size--;
	}

	while (num != 0) {
		tmp_st.push(num % b);
		num /= b;
	}

	while (!tmp_st.empty()) {
		cout << tmp_st.top() << " ";
		tmp_st.pop();
	}
	cout << endl;

	return 0;
}