#include <iostream>
using namespace std;

int N, W;
int dp[1024][1024];

pair<int, int> prev_pa, prev_pb;
int prev_a, prev_b;
int tmp_x, tmp_y;

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> W;
	for (int i = 1; i <= W; i++) {
		cin >> tmp_x >> tmp_y;

		for (int x = 0; x < i; x++) {
			dp[x][i] = prev_pb.first - tmp_x + prev_pb.second - tmp_y;
			
		}

		for (int y = 0; y < i; y++) {
			dp[i][y] = prev_pa.first - tmp_x + prev_pa.second - tmp_y;

		}



	}



	return 0;
}