// 模备 匙飘况农
// 坷饶 7:46 2018-09-05
// Disjoint Set

#include <iostream>
#include <unordered_map>
using namespace std;

struct nxt_friend {
	string name;
	int size;
};

unordered_map<string, nxt_friend> network;
unordered_map<string, nxt_friend>::iterator iter;

string find(string tmp) {
	iter = network.find(tmp);
	if (iter == network.end()) return tmp;
	iter->second = find(iter->second);
	return iter->second;
}

void merge(string a, string b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
}

int main() {

	return 0;
}