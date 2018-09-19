// DFS¿Í BFS
// 4:55 PM 9/19/2018


// DFS - stack.
// BFS - queue.

#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int val;
	vector<int> connected;
	bool visited = false;
};

Node nodes[1024];

int cnt_node, cnt_edge, startNode;
int tmp1, tmp2;

void DFS(int n) {
	printf("%d ", n);
	nodes[n].visited = true;
	vector<int>::iterator iter = nodes[n].connected.begin();
	while (iter != nodes[n].connected.end()) {
		if(!nodes[*iter].visited) DFS(*iter);
		iter++;
	}
}

void BFS(int n) {
	nodes[n].visited = true;
	vector<int>::iterator iter = nodes[n].connected.begin();
	while (iter != nodes[n].connected.end()) {
		if (!nodes[*iter].visited) printf("%d ", *iter);
		iter++;
	}

	iter = nodes[n].connected.begin();
	while (iter != nodes[n].connected.end()) {
		if (!nodes[*iter].visited) BFS(*iter);
		iter++;
	}
}

int main() {

	scanf("%d %d %d", &cnt_node, &cnt_edge, &startNode);
	for (int i = 1; i <= cnt_node; i++) nodes[i].val = i;

	for (int i = 0; i < cnt_edge; i++) {
		scanf("%d %d", &tmp1, &tmp2);

		nodes[tmp1].connected.push_back(tmp2);
		nodes[tmp2].connected.push_back(tmp1);
	}

	DFS(startNode);
	for (int i = 1; i <= cnt_node; i++) nodes[i].visited = false;

	printf("\n%d ", startNode);
	BFS(startNode);

	return 0;
}