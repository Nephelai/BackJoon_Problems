#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

int N;
set<int, greater<int>> neg;
set<int>::iterator neg_iter;
set<int> pos;
set<int>::iterator pos_iter;
int tmp;
int res_x, res_y;

void MinSolution() {
	int res;
	neg_iter = neg.begin();
	pos_iter = pos.begin();

	if (neg_iter == neg.end()) {
		cout << *pos_iter << ' ';
		pos_iter++;
		cout << *pos_iter << endl;
		return;
	}

	if (pos_iter == pos.end()) {
		cout << *neg_iter << ' ';
		neg_iter++;
		cout << *neg_iter << endl;
		return;
	}

	res = *neg_iter + *pos_iter;
	res_x = *neg_iter;
	res_y = *pos_iter;

	neg_iter++;
	pos_iter++;

	if (pos_iter != pos.end()) {
		if (abs(res_y + *pos_iter) < abs(res)) {
			res = res_y + *pos_iter;
			res_x = res_y;
			res_y = *pos_iter;
		}
	}

	if (neg_iter != neg.end()) {
		if (abs(res_x + *neg_iter) < abs(res)) {
			res = res_x + *neg_iter;
			res_y = *neg_iter;
		}
	}

	neg_iter--;
	pos_iter--;

	while (pos_iter != pos.end() && neg_iter != neg.end()) {
		if (res < 0) {
			pos_iter++;
			if (pos_iter == pos.end())
				break;
			tmp = *neg_iter + *pos_iter;
			if (abs(res) > abs(tmp)) {
				res = *neg_iter + *pos_iter;
				res_x = *neg_iter;
				res_y = *pos_iter;
			}
		}
		else {
			neg_iter++;
			if (neg_iter == neg.end())
				break;
			tmp = *neg_iter + *pos_iter;
			if (abs(res) > abs(tmp)) {
				res = *neg_iter + *pos_iter;
				res_x = *neg_iter;
				res_y = *pos_iter;
			}
		}
		res = tmp;
	}

	cout << res_x << " " << res_y << endl;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp > 0)
			pos.insert(tmp);
		else
			neg.insert(tmp);
	}
	MinSolution();

	return 0;
}