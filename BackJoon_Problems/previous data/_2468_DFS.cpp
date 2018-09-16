#include <iostream>
#include <set>
using namespace std;

int space_size;
struct Node {
	int h;
	Node *up;
	Node *bot;
	Node *left;
	Node *right;
	bool visited[110] = { false };
};

Node space[10210];
set<int> var_h;
set<int>::iterator iter;

int tmp_max, tot_max;

void DFS(Node &curr, int curr_h) {
	curr.visited[curr_h] = true;
	if (curr.right != NULL && curr.right->h > curr_h && curr.right->visited[curr_h] == false) {
		DFS(*curr.right, curr_h);
	}
	if (curr.left != NULL && curr.left->h > curr_h && curr.left->visited[curr_h] == false) {
		DFS(*curr.left, curr_h);
	}
	if (curr.up != NULL && curr.up->h > curr_h && curr.up->visited[curr_h] == false) {
		DFS(*curr.up, curr_h);
	}
	if (curr.bot != NULL && curr.bot->h > curr_h && curr.bot->visited[curr_h] == false) {
		DFS(*curr.bot, curr_h);
	}
}

int main() {
	scanf("%d", &space_size);
	Node tmp;
	for (int i = 0; i < space_size * space_size; i++) {
		scanf("%d", &tmp.h);
		var_h.insert(tmp.h);

		tmp.up = &space[i - space_size];
		tmp.bot = &space[i + space_size];
		tmp.left = &space[i - 1];
		tmp.right = &space[i + 1];

		if (i / space_size == 0) {
			tmp.up = NULL;
		}
		if (i % space_size == 0) {
			tmp.left = NULL;
		}
		if (i % space_size == space_size - 1) {
			tmp.right = NULL;
		}
		if (i / space_size == space_size - 1) {
			tmp.bot = NULL;
		}

		space[i] = tmp;

	}

	for (iter = var_h.begin(); iter != var_h.end(); iter++) {
		// 한 부분에 물의 높이 보다 높으면 발생
		for (int i = 0; i < space_size * space_size; i++) {
			if (space[i].h > *iter && space[i].visited[*iter] == false) {
				DFS(space[i], *iter);
				tmp_max += 1;
			}
			// 물 높이에 대한 검색 완료
		}

		if (tmp_max > tot_max)
			tot_max = tmp_max;
		tmp_max = 0;
	}

	var_h.clear();
	if (tot_max == 0)
		tot_max = 1;
	printf("%d\n", tot_max);

	return 0;
}