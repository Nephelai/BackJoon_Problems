#include <iostream>
#include <set>
#include <functional>
using namespace std;

int N;
set<int, greater<int>> neg;
set<int>::iterator neg_iter;
set<int> pos;
set<int>::iterator pos_iter;
int tmp;

int min_val = 0x7FFFFFFF;

int min_x, min_y;
int tmp_x, tmp_y;

void FirstCheck() {
	neg_iter = neg.begin();
	pos_iter = pos.begin();

	if (neg.size() > 1) {
		min_y = *neg_iter;
		neg_iter++;
		min_x = *neg_iter;
		min_val = min_x + min_y;
	}

	if (pos.size() > 1) {
		tmp_x = *pos_iter;
		pos_iter++;
		tmp_y = *pos_iter;
		tmp = tmp_x + tmp_y;
		if (abs(tmp) < abs(min_val)) {
			min_val = tmp;
			min_x = tmp_x;
			min_y = tmp_y;
		}
	}
}

void MinSolution() {
	neg_iter = neg.begin();
	pos_iter = pos.begin();

	while (pos_iter != pos.end() && neg_iter != neg.end())	{
		tmp_x = *neg_iter;
		tmp_y = *pos_iter;
		tmp = tmp_x + tmp_y;
		if (abs(tmp) < abs(min_val)) {
			min_val = tmp;
			min_x = tmp_x;
			min_y = tmp_y;
		}

		if (tmp < 0)
			pos_iter++;
		else
			neg_iter++;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp < 0)
			neg.insert(tmp);
		else
			pos.insert(tmp);
	}

	FirstCheck();
	MinSolution();

	cout << min_x << " " << min_y << endl;

	return 0;
}