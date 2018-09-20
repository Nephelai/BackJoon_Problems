// ¿Ø±‚≥Û πË√ﬂ
// 10:25 PM 9/20/2018

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
	int data = 0;
	bool visit = false;
};

Node nodes[50][50];
vector<pair<int, int>> cabbages;

char c;
int t, N_x, N_y, cnt, tmp, idx, warms;

void FindWarms(int x, int y) {
	if (nodes[x][y].visit) return;

	stack<Node> _stack;
	_stack.push(nodes[x][y]);
	int _x, _y;
	while (!_stack.empty()) {
		_x = _stack.top().x;
		_y = _stack.top().y;

		_stack.pop();
		if (nodes[_x][_y].visit) continue;
		nodes[_x][_y].visit = true;

		// check 4-direct
		if (_x > 0 && nodes[_x - 1][_y].data == 1) _stack.push(nodes[_x - 1][_y]);
		if (_y > 0 && nodes[_x][_y - 1].data == 1) _stack.push(nodes[_x][_y - 1]);
		if (_x + 1 < N_x  && nodes[_x + 1][_y].data == 1) _stack.push(nodes[_x + 1][_y]);
		if (_y + 1 < N_y  && nodes[_x][_y + 1].data == 1) _stack.push(nodes[_x][_y + 1]);
	}

	warms++;
}

int main() {
	int t, num1, num2;
	scanf("%d", &t);
	while (t--)	{
		scanf("%d %d %d", &N_x, &N_y, &cnt);
		for (int i = 0; i < cnt; i++) {
			scanf("%d %d", &num1, &num2);
			nodes[num1][num2].x = num1;
			nodes[num1][num2].y = num2;
			nodes[num1][num2].data = 1;

			cabbages.push_back({ num1, num2 });
		}

		for (int i = 0; i < cnt; i++) {
			FindWarms(cabbages[i].first, cabbages[i].second);
		}

		printf("%d\n", warms);

		// Initialize
		warms = 0;
		cabbages.clear();
		for (int x = 0; x < N_x; x++) {
			for (int y = 0; y < N_y; y++) {
				nodes[x][y].data = 0;
				nodes[x][y].visit = false;
			}
		}

	}
	return 0;
}