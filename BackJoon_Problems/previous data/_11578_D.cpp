#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

int N, M;
vector<int> p_vec;
set<int> p_set;
set<int>::iterator iter_a;
// x : student, y : problem
int sol_cnt, sol_num;

int tmp_sol;

int main() {
	scanf("%d%d", &N, &M);

	N = pow(2, N + 1) - 1;
	for (int i = 0; i < M; i++) {
		tmp_sol = 0;
		scanf("%d", &sol_cnt);
		for (int j = 0; j < sol_cnt; j++) {
			scanf("%d", &sol_num);
			sol_num--;
			tmp_sol += pow(2, sol_num);
		}
		p_set.insert(tmp_sol);
	}
		


	return 0;
}