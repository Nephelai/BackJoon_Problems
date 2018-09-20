// 단지번호붙이기
// 9:17 PM 9/20/2018

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

Node nodes[25][25];
vector<int> apts;

char c;
int N, tmp, idx;

void FindApt(int x, int y) {
	int cnt = 0;
	stack<Node> _stack;
	_stack.push(nodes[x][y]);
	int _x, _y;
	while (!_stack.empty()) {
		_x = _stack.top().x;
		_y = _stack.top().y;

		_stack.pop();
		if (nodes[_x][_y].visit) continue;
		cnt++;
		nodes[_x][_y].visit = true;

		// check 4-direct
		if (_x > 0 && nodes[_x - 1][_y].data == 1) _stack.push(nodes[_x - 1][_y]);
		if (_y > 0 && nodes[_x][_y - 1].data == 1) _stack.push(nodes[_x][_y - 1]);
		if (_x + 1 < N  && nodes[_x + 1][_y].data == 1) _stack.push(nodes[_x + 1][_y]);
		if (_y + 1 < N  && nodes[_x][_y + 1].data == 1) _stack.push(nodes[_x][_y + 1]);
	}

	apts.push_back(cnt);
}

int main() {
	idx = 0;
	scanf("%d ", &N);
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			scanf("%c", &c);
			if (c == '1') {
				nodes[x][y].x = x;
				nodes[x][y].y = y;
				nodes[x][y].data = 1;
			}
		}
		scanf("%c", &c);
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (nodes[x][y].data && !nodes[x][y].visit) {
				FindApt(x, y);
			}
		}
	}

	sort(apts.begin(), apts.end());
	printf("%d\n", apts.size());
	for (int i = 0; i < apts.size(); i++) printf("%d\n", apts[i]);

	return 0;
}