#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	int val;
	int A_x, A_y;
	int B_x, B_y;
};

int N, W;
int w_x, w_y;

point dp[1024][1024];

int prev_A, prev_B;
int tmp_A, tmp_B;

int Dist(int _x, int _y, int w_x, int w_y) {
	return  abs(_x - w_x) + abs(_y - w_y);
}

int main() {
	cin >> N >> W;

	for (int i = 0; i < W; i++) {
		cin >> w_x >> w_y;
		for (int y = 0; y < i + 1; y++) {
			tmp_A = dp[prev_A][y].val + Dist(dp[prev_A][y].A_x, dp[prev_A][y].A_y, w_x, w_y);
			tmp_B = dp[i + 1][prev_B].val + Dist(dp[i + 1][prev_B].B_x, dp[i + 1][prev_B].B_y, w_x, w_y);
			if (tmp_A < tmp_B) {
				dp[i + 1][y].A_x = w_x;
				dp[i + 1][y].A_y = w_y;
				dp[i + 1][y].val = tmp_A;
				dp[i + 1][y].B_x = dp[prev_A][y].B_x;
				dp[i + 1][y].B_y = dp[prev_A][y].B_y;
				
				prev_A = i;
			}
			else {
				dp[i + 1][y].B_x = w_x;
				dp[i + 1][y].B_y = w_y;
				dp[i + 1][y].val = tmp_B;
				dp[i + 1][y].A_x = dp[i + 1][y].A_x;
				dp[i + 1][y].A_y = dp[i + 1][y].A_y;

				prev_B = i;
			}

			
		}
		for (int x = 0; x < i + 1; x++) {


		}

	}
	return 0;
}