#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*

class Stack {
public:
	void Push(int n);
	int Pop();
	bool isEmpty();

private:
	int top = -1;
	int data[1024];
};

void Stack::Push(int n) {
	top++;
	data[top] = n;
}

int Stack::Pop() {
	if (!isEmpty()) {
		int tmp = data[top];
		top--;
		return tmp;
	}
	else
		return 0;
}

bool Stack::isEmpty() {
	if (top == -1) return true;
	else return false;
}

class Queue{
public:
	void Push(int n);
	int Pop();
	bool isEmpty();

private:
	int front = 0;
	int end = 0;
	int data[1024];
};

void Queue::Push(int n) {
	data[end] = n;
	end++;
}

int Queue::Pop() {
	if (!isEmpty()) {
		int tmp = data[front];
		front++;
		return tmp;
	}
	else
		return 0;
}

bool Queue::isEmpty() {
	if (front == end) return true;
	else return false;
}

*/
struct AdjMatrix {
	bool connected[1024] = { false, };
	bool visited = false;
};

AdjMatrix map[1024];
int vertexs, edges, startNode;
int num1, num2;


// Stack 만으로 DFS 구성이 가능한가?
// 거꾸로 넣으면..?
void DFS(int s) {
	stack<int> _stack;
	_stack.push(s);
	int tmp = -1;
	while (!_stack.empty()) {
		tmp = _stack.top();
		_stack.pop();
		if (map[tmp].visited) continue;
		printf("%d ", tmp);
		map[tmp].visited = true;
		for (int i = vertexs; i > 0; i--) {
			if (map[tmp].connected[i] && !map[i].visited) _stack.push(i);
		}
	}
}

void BFS(int s) {
	queue<int> _queue;
	_queue.push(s);
	int tmp = -1;
	while (!_queue.empty()) {
		tmp = _queue.front();
		_queue.pop();
		if (map[tmp].visited) continue;
		printf("%d ", tmp);
		map[tmp].visited = true;
		for (int i = 1; i <= vertexs; i++) {
			if (map[tmp].connected[i] && !map[i].visited) _queue.push(i);
		}
	}
}


int main() {
	scanf("%d %d %d", &vertexs, &edges, &startNode);
	for (int i = 0; i < edges; i++) {
		scanf("%d %d", &num1, &num2);
		map[num1].connected[num2] = true;
		map[num2].connected[num1] = true;
	}

	DFS(startNode);
	for (int i = 1; i <= vertexs; i++) map[i].visited = false;
	printf("\n");
	BFS(startNode);

	return 0;
}